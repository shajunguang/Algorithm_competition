# Redis

### Redis优缺点

redis配合消息队列，适用于高并发的场景，可以大大减少对后端数据库的压力。
redis可以用来做缓存，做阻塞队列，发布/订阅， 还可以用来计数，排行等等，高级地redis还有集群，哨兵 ， 分布式锁等（zookeeper使用）
但是redis也有缺点：
1) 与后端数据库的数据一致性问题 
2) 缓存雪崩
3) 缓存击穿
4) 缓存的并发竞争问题

### Redis数据类型

Redis支持五种数据类型：string（字符串），hash（哈希），list（列表），set（集合）及zset(sorted set：有序集合)。

| 类型                 | 简介                                                   | 特性                                                         | 场景                                                         | 命令                           |
| :------------------- | :----------------------------------------------------- | :----------------------------------------------------------- | :----------------------------------------------------------- | ------------------------------ |
| String(字符串)       | 二进制安全                                             | 可以包含任何数据,比如jpg图片或者序列化的对象,一个值最大能存储512M | String数据结构是简单的key-value类型，value其实不仅可以是String，也可以是数字。 常规key-value缓存应用； 常规计数：微博数，粉丝数等。 | set,get,decr,incr,mget 等。    |
| Hash(字典)           | 键值对集合,即Map类型                                   | 适合存储对象,并且可以像数据库中update一个属性一样只修改某一项属性值 | 存储、读取、修改用户属性                                     | hget,hset,hgetall 等。         |
| List(列表)           | 链表(双向链表)                                         | 增删快,提供了操作某一段元素的API                             | 微博的关注列表，粉丝列表，消息列表等功能都可以用Redis的 list 结构来实现。 | lpush,rpush,lpop,rpop,lrange等 |
| Set(集合)            | 哈希表实现,元素不重复                                  | 添加、删除,查找的复杂度都是O(1)；为集合提供了求交集、并集、差集等操作 | 共同好友；利用唯一性,统计访问网站的所有独立ip ；好友推荐时,根据tag求交集,大于某个阈值就可以推荐 | sadd,spop,smembers,sunion 等   |
| Sorted Set(有序集合) | 将Set中的元素增加一个权重参数score,元素按score有序排列 | 数据插入集合时,已经进行天然排序                              | 在直播系统中，实时排行信息包含直播间在线用户列表，各种礼物排行榜，弹幕消息（可以理解为按消息维度的消息排行榜）等信息 | zadd,zrange,zrem,zcard等       |

- 字符串String

  Redis 中的字符串是一种 **动态字符串**SDS，这意味着使用者可以修改，它的底层实现有点类似于 Java 中的 **ArrayList**，有一个字符数组。**Redis 为了对内存做极致的优化，不同长度的字符串使用不同的结构体来表示。**

  **SDS与C字符串的区别**

  - **计数方式不同**

  C语言对字符串长度的统计，就完全来自遍历，从头遍历到末尾，直到发现空字符就停止，以此统计出字符串的长度。

  而Redis本身就保存了长度的信息，所以我们获取长度的时间复杂度为0（1）

  - **杜绝缓冲区溢出**

  字符串拼接是我们经常做的操作，在C和Redis中一样，也是很常见的操作，但是问题就来了，C是不记录字符串长度的，一旦我们调用了拼接的函数，如果没有提前计算好内存，是会产生缓存区溢出的。

  SDS结构存储了当前长度，还有free未使用的长度，那简单呀，你现在做了拼接操作，我去判断一些是否可以放得下，如果长度够就直接执行，如果不够，那我就进行扩容。

  - **减少修改字符串时带来的内存重分配次数**

  C语言字符串底层也是一个数组，每次创建的时候就创建一个N+1长度的字符，多的那个1，就是为了保存空字符的。

  Redis是个高速缓存数据库，如果我们需要对字符串进行频繁的拼接和截断操作，如果我们写代码忘记了重新分配内存，就可能造成缓冲区溢出，以及内存泄露。

  Redis为了避免C字符串这样的缺陷，就分别采用了两种解决方案，去达到性能最大化，空间利用最大化：

  - 空间预分配：当我们对SDS进行扩展操作的时候，Redis会为SDS分配好内存，并且根据特定的公式，分配多余的free空间，还有多余的1byte空间（这1byte也是为了存空字符），这样就可以避免我们连续执行字符串添加所带来的内存分配消耗。

    比如现在有这样的一个字符：

  ![img](https://mmbiz.qpic.cn/mmbiz_jpg/uChmeeX1FpyGibGCzNkDJFYibmZYhAmR0icfCzh2Sb1xWcVgEfRhAJHuiaibVRiaxd36wWejk0Uo3iaNsR8VQjbZDQOPg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

  我们调用了拼接函数，字符串边长了，Redis还会根据算法计算出一个free值给他备用：

  ![img](https://mmbiz.qpic.cn/mmbiz_jpg/uChmeeX1FpyGibGCzNkDJFYibmZYhAmR0icgybRUBuzg1gcz9rOkAibrbY1rYbIYkFcQJqOhJ99BmVoJ8ax53ALYYA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

  我们再继续拼接，你会发现，备用的free用上了，省去了这次的内存重分配：

  ![img](https://mmbiz.qpic.cn/mmbiz_jpg/uChmeeX1FpyGibGCzNkDJFYibmZYhAmR0iciczRhKNaiaaYZnuiaiarKEoMk7QHtltuO4cpBo7ho633FKFC9s4sgemuYQ/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

  - 惰性空间释放：刚才提到了会预分配多余的空间，当我们执行完一个字符串缩减的操作，redis并不会马上收回我们的空间，因为可以预防你继续添加的操作，这样可以减少分配空间带来的消耗，但是当你再次操作还是没用到多余空间的时候，Redis也还是会收回对于的空间，防止内存的浪费的。

    还是一样的字符串：

  ![img](https://mmbiz.qpic.cn/mmbiz_jpg/uChmeeX1FpyGibGCzNkDJFYibmZYhAmR0icFcnp22okB2XsLq9F4G79nlsv6puric5RZxYjIMxsbopVc0EkbngE6ww/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

  当我们调用了删减的函数，并不会马上释放掉free空间：

  ![img](https://mmbiz.qpic.cn/mmbiz_jpg/uChmeeX1FpyGibGCzNkDJFYibmZYhAmR0icibTYCgRSBGibz2p06n96a8LLS1uD9jeNGBecYrUlQyVfibfeNeAMxrvoA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

  如果我们需要继续添加这个空间就能用上了，减少了内存的重分配，如果空间不需要了，调用函数删掉就好了。

  - **二进制安全**

  仔细看的仔肯定看到上面我不止一次提到了空字符也就是’\0‘，C语言是判断空字符去判断一个字符的长度的，但是有很多数据结构经常会穿插空字符在中间，比如图片，音频，视频，压缩文件的二进制数据，就比如下面这个单词，他只能识别前面的 不能识别后面的字符，那对于我们开发者而言，这样的结果显然不是我们想要的对不对。

  ![img](https://mmbiz.qpic.cn/mmbiz_jpg/uChmeeX1FpyGibGCzNkDJFYibmZYhAmR0icarShMiaxCsiadWlW08ib3LbJuLKjOZBgAN0GAdOzcanTgave1pK5auTJA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

  Redis就不存在这个问题了，他不是保存了字符串的长度嘛，他不判断空字符，他就判断长度对不对就好了，所以redis也经常被我们拿来保存各种二进制数据，我反正是用的很high，经常用来保存小文件的二进制。

  ![img](https://mmbiz.qpic.cn/mmbiz_jpg/uChmeeX1FpyGibGCzNkDJFYibmZYhAmR0ic7xAUXbVjTh11HOMK260D70WYPS458S3y0FhIzW6RyrXzKRTEFnU6RA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

  

- 字典Hash

  Redis 中的字典相当于 Java 中的 **HashMap**，内部实现也差不多类似，都是通过 **"数组 + 链表"** 的链地址法来解决部分 **哈希冲突**，同时这样的结构也吸收了两种不同数据结构的优点。

  `table` 属性是一个数组，数组中的每个元素都是一个指向 `dict.h/dictEntry` 结构的指针，而每个 `dictEntry` 结构保存着一个键值对。

  **实际上字典结构的内部包含两个 hashtable**，通常情况下只有一个 hashtable 是有值的，但是在字典扩容缩容时，需要分配新的 hashtable，然后进行 **渐进式搬迁**。

  - **渐进式rehash**

    大字典的扩容是比较耗时间的，需要重新申请新的数组，然后将旧字典所有链表中的元素重新挂接到新的数组下面，这是一个 O(n) 级别的操作，作为单线程的 Redis 很难承受这样耗时的过程，所以 Redis 使用 **渐进式 rehash** 小步搬迁。

    渐进式 rehash 会在 rehash 的同时，保留新旧两个 hash 结构，查询时会同时查询两个 hash 结构，然后在后续的定时任务以及 hash 操作指令中，循序渐进的把旧字典的内容迁移到新字典中。当搬迁完成了，就会使用新的 hash 结构取而代之。

  - 扩缩容的条件

    正常情况下，当 hash 表中 **元素的个数等于第一维数组的长度时**，就会开始扩容，扩容的新数组是 **原数组大小的 2 倍**。不过如果 Redis 正在做 `bgsave(持久化命令)`，为了减少内存也得过多分离，Redis 尽量不去扩容，但是如果 hash 表非常满了，**达到了第一维数组长度的 5 倍了**，这个时候就会 **强制扩容**。

    当 hash 表因为元素逐渐被删除变得越来越稀疏时，Redis 会对 hash 表进行缩容来减少 hash 表的第一维数组空间占用。所用的条件是 **元素个数低于数组长度的 10%**，缩容不会考虑 Redis 是否在做 `bgsave`。


### 压缩表

功能是将一系列数据与其编码信息存储在一块连续的内存区域，这块内存物理上是连续的，逻辑上被分为多个组成部分，其目的是在一定可控的时间复杂读条件下尽可能的减少不必要的内存开销，从而达到节省内存的效果。

![image-20200818102449497](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200818102449497.png)



### 跳表

![image-20200818103559140](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200818103559140.png)





### 渐进式rehash

![image-20200818103226573](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200818103226573.png)



#### 采用渐进式 rehash 的原因

扩展或收缩哈希表需要将ht[0]中的所有键值对rehash到ht[1]中。不过，这个rehash的动作不一定是一次性、集中式完成的，而是分多次、渐进式完成的。

这样做的原因在于，避免当ht[0]中保存了太多的键值对时，一次性集中式rehash让服务器在较长的时间内停止服务。rehash动作的过程中肯定是不能对外提供增删改查的操作的，如果ht[0]中只有四个键值对的话，那么一次性完成rehash也不会对服务器的运行造成太多延迟，但如果是四百万、四千万的话一次性完成rehash将会严重阻塞服务器运行。

#### 渐进式 rehash 的过程

以下是哈希表渐进式rehash的详细步骤：

1. 为ht[1]分配空间，让字典同时持有ht[0]和ht[1]两个哈希表。
2. 在字典中维护一个rehashidx变量，来标记当前rehash到了ht[0] 的 dictEntry table哪个位置。
3. 在渐进式rehash进行期间，每次对字典执行增删改查操作时，除了执行指定操作外还要讲ht[0]中的rehashidx索引位置上的键值对 rehash 到ht[1]上，当本次rehash完成时，rehashidx加一。
4. 随着字典操作的不断进行，最终在某个时间点上，ht[0]上的键值对都 rehash 到了ht[1]上，这时程序将 rehashidx 设置为-1，表示 rehash 操作已经完成。
5. rehash 完所有键值对后，ht[1]和ht[0]将交换位置，即ht[1]将成为新的ht[0]。

渐进式 rehash 采用了**分治**的思想，将 rehash 键值对所需的工作分摊到了每次对字典的增删改查操作上，虽然降低了 redis 服务器的整体吞吐量，但提升了响应速度，不会出现在某次操作时特别慢的情况。

#### 渐进式 rehash 期间的哈希表操作

因为在渐进式 rehash 的过程中，字典会同时使用 ht[0] 和 ht[1] 两个哈希表，所以在这个过程中对字典的增删改查操作会在两个哈希表上进行。例如在字典上查找一个键时，程序会先查询ht[0]，如果没有查到就再查 ht[1]。
 新添加到字典上的键值对只会保存在ht[1]上，而ht[0]上不再进行任何添加操作，这样就保证了ht[0]中包含的键值对的数量只减不增，并随着rehash的进行而逐渐变成空表。

#### 总结

- 原因：数据太多的话一次rehash可能让服务器长时间停止服务，渐进式就是将停止服务的时间分散给一段时间内的每次增删改查上。
- 渐进：rehashidx 从0开始到ht[0].length-1，每次增删改查时 将对ht[rehashidx]进行rehash。
- 操作：查询操作同时查询ht[0]和ht[1]，新增操作只新增ht[1]



### Redis线程模型

redis 内部使用文件事件处理器 `file event handler`，这个文件事件处理器是单线程的，所以 redis 才叫做单线程的模型。它采用 IO 多路复用机制同时监听多个 socket，根据 socket 上的事件来选择对应的事件处理器进行处理。

文件事件处理器的结构包含 4 个部分：

- 多个 socket
- IO 多路复用程序
- 文件事件分派器
- 事件处理器（连接应答处理器、命令请求处理器、命令回复处理器）

多个 socket 可能会并发产生不同的操作，每个操作对应不同的文件事件，但是 IO 多路复用程序会监听多个 socket，会将 socket 产生的事件放入队列中排队，事件分派器每次从队列中取出一个事件，把该事件交给对应的事件处理器进行处理。



### Redis设置过期时间

如果假设你设置了一批 key 只能存活1个小时，那么接下来1小时后，redis是怎么对这批key进行删除的？

- **定期删除**：redis默认是每隔 100ms 就**随机抽取**一些设置了过期时间的key，检查其是否过期，如果过期就删除。注意这里是随机抽取的。为什么要随机呢？你想一想假如 redis 存了几十万个 key ，每隔100ms就遍历所有的设置过期时间的 key 的话，就会给 CPU 带来很大的负载！
- **惰性删除** ：定期删除可能会导致很多过期 key 到了时间并没有被删除掉。所以就有了惰性删除。假如你的过期 key，靠定期删除没有被删除掉，还停留在内存里，除非你的系统去查一下那个 key，才会被redis给删除掉。

注：如果大量的key过期时间设置的过于集中，到过期的那个时间点，**Redis**可能会出现短暂的卡顿现象。严重的话会出现缓存雪崩，我们一般需要在时间上加一个随机值，使得过期时间分散一些。



### 内存淘汰机制

**redis 提供 6种数据淘汰策略：**

1. **volatile-lru**：从已设置过期时间的数据集（server.db[i].expires）中挑选最近最少使用的数据淘汰
2. **volatile-ttl**：从已设置过期时间的数据集（server.db[i].expires）中挑选将要过期的数据淘汰
3. **volatile-random**：从已设置过期时间的数据集（server.db[i].expires）中任意选择数据淘汰
4. **allkeys-lru**：当内存不足以容纳新写入数据时，在键空间中，移除最近最少使用的key（这个是最常用的）
5. **allkeys-random**：从数据集（server.db[i].dict）中任意选择数据淘汰
6. **no-eviction**：禁止驱逐数据，也就是说当内存不足以容纳新写入数据时，新写入操作会报错。这个应该没人使用吧！

4.0版本后增加以下两种：

1. **volatile-lfu**：从已设置过期时间的数据集(server.db[i].expires)中挑选最不经常使用的数据淘汰

2. **allkeys-lfu**：当内存不足以容纳新写入数据时，在键空间中，移除最不经常使用的key

   

### 手写LRU算法

```java
public class LRUCache<K, V> extends LinkedHashMap<K, V> {
    
private final int CACHE_SIZE;

    // 这里就是传递进来最多能缓存多少数据
    public LRUCache(int cacheSize) {
        super((int) Math.ceil(cacheSize / 0.75) + 1, 0.75f, true); // 这块就是设置一个hashmap的初始大小，同时最后一个true指的是让linkedhashmap按照访问顺序来进行排序，最近访问的放在头，最老访问的就在尾
        CACHE_SIZE = cacheSize;
    }

    @Override
    protected boolean removeEldestEntry(Map.Entry eldest) {
        return size() > CACHE_SIZE; // 这个意思就是说当map中的数据量大于指定的缓存个数的时候，就自动删除最老的数据
    }

}
```



### 缓存不一致

比如超卖问题 。 缓存中的数据已经失效 ，和DB中数据不一样 ，可是还没来得及修改。这时候再读取
cache提供的就是一个错误的数据。

- 读：先判断redis中是否存在，如存在的从redis中读取并使用，如无再从mysql中读取，然后再回写
  redis

- 改：先操作redis中是否存在，如存在则进行改操作，再进行mysql操作数据，如无则先改mysql中数
  据，然后回写redis

- 写：先将数据写入mysql，然后再写入redis

- 删：先操作redis中是否存在，如无，则直接删除mysql中数据，如有，刚先删除redis中数据，再删除
  mysql中数据

  以上是redis与mysql进行合作时，对数据进行增删改查的数据同步操作步骤。

解决方法 ：必须使用一定的读取策略来解决

**延迟加载**
读：当读请求到来时，先从缓存读，如果读不到就从数据库读，读完之后同步到缓存且添加过期时间
写：当写请求到来时，只写数据库
优点：仅对请求的数据进行一段时间的缓存，没有请求过的数据就不会被缓存，节省缓存空间；节点出现
故障并不是致命的，因为可以从数据库中得到
缺点：缓存数据不是最新的；【缓存击穿】；【缓存失效】不一致

**直写**

读：当读请求到来时，只从缓存读
写：当写请求到来时，先写数据库然后同步到缓存，设置为永不过期
优点：缓存数据永不过时且为最新
缺点：每次写入都需要写缓存导致的性能损失；重启节点或故障会导致缓存数据的丢失直到有写操作同步
到缓存；大量数据可能没有被读取的资源浪费

### 持久化机制

Redis不同于Memcached的很重一点就是，Redis支持持久化，而且支持两种不同的持久化操作。**Redis的一种持久化方式叫快照（snapshotting，RDB），另一种方式是只追加文件（append-only file,AOF）**。

**快照（snapshotting）持久化（RDB）**

Redis可以通过创建快照来获得存储在内存里面的数据在某个时间点上的副本。Redis创建快照之后，可以对快照进行备份，可以将快照复制到其他服务器从而创建具有相同数据的服务器副本（Redis主从结构，主要用来提高Redis性能），还可以将快照留在原地以便重启服务器的时候使用。

快照持久化是Redis默认采用的持久化方式。

![image-20200728201206028](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728201206028.png)

![image-20200728201242757](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728201242757.png)

![image-20200728201320422](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728201320422.png)

![image-20200728201341652](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728201341652.png)

![image-20200728201601993](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728201601993.png)

**AOF（append-only file）持久化**

与快照持久化相比，AOF持久化 的实时性更好，因此已成为主流的持久化方案。默认情况下Redis没有开启AOF（append only file）方式的持久化，可以通过appendonly参数开启：

```conf
appendonly yesCopy to clipboardErrorCopied
```

开启AOF持久化后每执行一条会更改Redis中的数据的命令，Redis就会将该命令写入硬盘中的AOF文件。AOF文件的保存位置和RDB文件的位置相同，都是通过dir参数设置的，默认的文件名是appendonly.aof。

在Redis的配置文件中存在三种不同的 AOF 持久化方式，它们分别是：

```conf
appendfsync always    #每次有数据修改发生时都会写入AOF文件,这样会严重降低Redis的速度
appendfsync everysec  #每秒钟同步一次，显示地将多个写命令同步到硬盘
appendfsync no        #让操作系统决定何时进行同步Copy to clipboardErrorCopied
```

为了兼顾数据和写入性能，用户可以考虑 appendfsync everysec选项 ，让Redis每秒同步一次AOF文件，Redis性能几乎没受到任何影响。而且这样即使出现系统崩溃，用户最多只会丢失一秒之内产生的数据。当硬盘忙于执行写入操作的时候，Redis还会优雅的放慢自己的速度以便适应硬盘的最大写入速度。

![image-20200728201645970](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728201645970.png)

![image-20200728201829273](C:\Users\96251\Desktop\image-20200728201829273.png)



![image-20200728201923292](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728201923292.png)

![image-20200728202001247](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728202001247.png)

**Redis 4.0 对于持久化机制的优化**

Redis 4.0 开始支持 RDB 和 AOF 的混合持久化（默认关闭，可以通过配置项 `aof-use-rdb-preamble` 开启）。

RDB做镜像全量持久化，AOF做增量持久化。因为RDB会耗费较长时间，不够实时，在停机的时候会导致大量丢失数据，所以需要AOF来配合使用。在redis实例重启时，会使用RDB持久化文件重新构建内存，再使用AOF重放近期的操作指令来实现完整恢复重启之前的状态。

如果把混合持久化打开，AOF 重写的时候就直接把 RDB 的内容写到 AOF 文件开头。这样做的好处是可以结合 RDB 和 AOF 的优点, 快速加载同时避免丢失过多的数据。当然缺点也是有的， AOF 里面的 RDB 部分是压缩格式不再是 AOF 格式，可读性较差。



### 缓存雪崩和缓存穿透问题解决方案

**什么是缓存雪崩？**

缓存同一时间大面积的失效，所以，后面的请求都会落到数据库上，造成数据库短时间内承受大量请求而崩掉。

**举个简单的例子**：如果所有首页的Key失效时间都是12小时，中午12点刷新的，我零点有个秒杀活动大量用户涌入，假设当时每秒 6000 个请求，本来缓存在可以扛住每秒 5000 个请求，但是缓存当时所有的Key都失效了。此时 1 秒 6000 个请求全部落数据库，数据库必然扛不住。此时，如果没用什么特别的方案来处理这个故障，重启数据库，但是数据库立马又被新的流量给打死了。这就是我理解的缓存雪崩。

**有哪些解决办法？**

处理缓存雪崩简单，在批量往**Redis**存数据的时候，把每个Key的失效时间都加个随机值就好了，这样可以保证数据不会在同一时间大面积失效。

```redis
setRedis（Key，value，time + Math.random() * 10000）；
```

- 事前：尽量保证整个 redis 集群的高可用性，发现机器宕机尽快补上, 主从+哨兵。选择合适的内存淘汰策略。
- 事中：本地ehcache缓存 + hystrix限流&降级，避免MySQL崩掉
- 事后：：**Redis** 持久化 **RDB**+**AOF**，一旦重启，自动从磁盘上加载数据，快速恢复缓存数据。![img](http://my-blog-to-use.oss-cn-beijing.aliyuncs.com/18-9-25/6078367.jpg)



**什么是缓存穿透？**

缓存穿透说简单点就是大量请求的 key 根本不存在于缓存中，导致请求直接到了数据库上，根本没有经过缓存这一层。举个例子：某个黑客故意制造我们缓存中不存在的 key 发起大量请求，导致大量请求落到数据库。

**正常缓存处理流程：**

![img](https://my-blog-to-use.oss-cn-beijing.aliyuncs.com/2019-11/%E6%AD%A3%E5%B8%B8%E7%BC%93%E5%AD%98%E5%A4%84%E7%90%86%E6%B5%81%E7%A8%8B-redis.png)

**缓存穿透情况处理流程：**

![img](https://my-blog-to-use.oss-cn-beijing.aliyuncs.com/2019-11/%E7%BC%93%E5%AD%98%E7%A9%BF%E9%80%8F%E5%A4%84%E7%90%86%E6%B5%81%E7%A8%8B-redis.png)

一般MySQL 默认的最大连接数在 150 左右，这个可以通过 `show variables like '%max_connections%';`命令来查看。最大连接数一个还只是一个指标，cpu，内存，磁盘，网络等无力条件都是其运行指标，这些指标都会限制其并发能力！所以，一般 3000 个并发请求就能打死大部分数据库了。

**有哪些解决办法？**

最基本的就是首先做好参数校验，一些不合法的参数请求直接抛出异常信息返回给客户端。比如查询的数据库 id 不能小于 0、传入的邮箱格式不对的时候直接返回错误消息给客户端等等。

**1）缓存无效 key** : 如果缓存和数据库都查不到某个 key 的数据就写一个到 redis 中去并设置过期时间，具体命令如下：`SET key value EX 10086`。这种方式可以解决请求的 key 变化不频繁的情况，如果黑客恶意攻击，每次构建不同的请求key，会导致 redis 中缓存大量无效的 key 。很明显，这种方案并不能从根本上解决此问题。如果非要用这种方式来解决穿透问题的话，尽量将无效的 key 的过期时间设置短一点比如 1 分钟。

另外，一般情况下我们是这样设计 key 的： `表名:列名:主键名:主键值`。

如果用 Java 代码展示的话，差不多是下面这样的：

```java
public Object getObjectInclNullById(Integer id) {
    // 从缓存中获取数据
    Object cacheValue = cache.get(id);
    // 缓存为空
    if (cacheValue == null) {
        // 从数据库中获取
        Object storageValue = storage.get(key);
        // 缓存空对象
        cache.set(key, storageValue);
        // 如果存储数据为空，需要设置一个过期时间(300秒)
        if (storageValue == null) {
            // 必须设置过期时间，否则有被攻击的风险
            cache.expire(key, 60 * 5);
        }
        return storageValue;
    }
    return cacheValue;
}Copy to clipboardErrorCopied
```

**2）布隆过滤器：**布隆过滤器是一个非常神奇的数据结构，通过它我们可以非常方便地判断一个给定数据是否存在与海量数据中。我们需要的就是判断 key 是否合法。具体是这样做的：把所有可能存在的请求的值都存放在布隆过滤器中，当用户请求过来，我会先判断用户发来的请求的值是否存在于布隆过滤器中。不存在的话，直接返回请求参数错误信息给客户端，存在的话才会走下面的流程。

![img](https://my-blog-to-use.oss-cn-beijing.aliyuncs.com/2019-11/%E5%B8%83%E9%9A%86%E8%BF%87%E6%BB%A4%E5%99%A8-%E7%BC%93%E5%AD%98%E7%A9%BF%E9%80%8F-redis.png)

### 布隆过滤器

**一种来检索元素是否在给定大集合中的数据结构，这种数据结构是高效且性能很好的，但缺点是具有一定的错误识别率和删除难度。并且，理论情况下，添加到集合中的元素越多，误报的可能性就越大。**

**当一个元素加入布隆过滤器中的时候，会进行如下操作：**

1. 使用布隆过滤器中的哈希函数对元素值进行计算，得到哈希值（有几个哈希函数得到几个哈希值）。
2. 根据得到的哈希值，在位数组中把对应下标的值置为 1。

**当我们需要判断一个元素是否存在于布隆过滤器的时候，会进行如下操作：**

1. 对给定元素再次进行相同的哈希计算；

2. 得到值之后判断位数组中的每个元素是否都为 1，如果值都为 1，那么说明这个值在布隆过滤器中，如果存在一个值不为 1，说明该元素不在布隆过滤器中。

   [![布隆过滤器hash计算](https://camo.githubusercontent.com/4900e946ca6ff5287f45c2b082f7e3ea4e143ed7/68747470733a2f2f6d792d626c6f672d746f2d7573652e6f73732d636e2d6265696a696e672e616c6979756e63732e636f6d2f323031392d31312f2545352542382538332545392539412538362545382542462538372545362542422541342545352539392541382d686173682545382542462539302545372541452539372e706e67)](https://camo.githubusercontent.com/4900e946ca6ff5287f45c2b082f7e3ea4e143ed7/68747470733a2f2f6d792d626c6f672d746f2d7573652e6f73732d636e2d6265696a696e672e616c6979756e63732e636f6d2f323031392d31312f2545352542382538332545392539412538362545382542462538372545362542422541342545352539392541382d686173682545382542462539302545372541452539372e706e67)

**布隆过滤器说某个元素存在，小概率会误判。布隆过滤器说某个元素不在，那么这个元素一定不在。**

**布隆过滤器使用场景**

1. 判断给定数据是否存在：比如判断一个数字是否在于包含大量数字的数字集中（数字集很大，5亿以上！）、 防止缓存穿透（判断请求的数据是否有效避免直接绕过缓存请求数据库）等等、邮箱的垃圾邮件过滤、黑名单功能等等。
2. 去重：比如爬给定网址的时候对已经爬取过的 URL 去重。



### 缓存击穿

**缓存击穿**，就是某个热点数据失效时，大量针对这个数据的请求会穿透到数据源。

解决这个问题有如下办法。

1. 可以使用互斥锁更新，保证同一个进程中针对同一个数据不会并发请求到 DB，减小 DB 压力。
2. 使用随机退避方式，失效时随机 sleep 一个很短的时间，再次查询，如果失败再执行更新。
3. 针对多个热点 key 同时失效的问题，可以在缓存时使用固定时间加上一个小的随机数，避免大量热点 key 同一时刻失效。



### 如果有大量的key需要设置同一时间过期，一般需要注意什么？

如果大量的key过期时间设置的过于集中，到过期的那个时间点，**Redis**可能会出现短暂的卡顿现象。严重的话会出现缓存雪崩，我们一般需要在时间上加一个随机值，使得过期时间分散一些。

**电商首页经常会使用定时任务刷新缓存，可能大量的数据失效时间都十分集中，如果失效时间一样，又刚好在失效的时间点大量用户涌入，就有可能造成缓存雪崩**



### Redis里面有1亿个key，其中有10w个key是以某个固定的已知的前缀开头的，如何将它们全部找出来？

使用**keys**指令可以扫出指定模式的key列表。

**如果这个redis正在给线上的业务提供服务，那使用keys指令会有什么问题？**

Redis的单线程的。keys指令会导致线程阻塞一段时间，线上服务会停顿，直到指令执行完毕，服务才能恢复。这个时候可以使用**scan**指令，**scan**指令可以无阻塞的提取出指定模式的key列表，但是会有一定的重复概率，在客户端做一次去重就可以了，但是整体所花费的时间会比直接用keys指令长。

**不过，增量式迭代命令也不是没有缺点的：举个例子， 使用 SMEMBERS 命令可以返回集合键当前包含的所有元素， 但是对于 SCAN 这类增量式迭代命令来说， 因为在对键进行增量式迭代的过程中， 键可能会被修改， 所以增量式迭代命令只能对被返回的元素提供有限的保证 。**



### Redis分布式锁

先拿**setnx**来争抢锁，抢到之后，再用**expire**给锁加一个过期时间防止锁忘记了释放。

在setnx之后执行expire之前进程意外crash或者要重启维护，锁就永远得不到释放。所以使用**setnx**和**expire**合成一条指令。



### Redis异步队列

一般使用list结构作为队列，**rpush**生产消息，**lpop**消费消息。当lpop没有消息的时候，要适当sleep一会再重试。

或者list还有个指令叫**blpop**，在没有消息的时候，它会阻塞住直到消息到来。

生产一次消费多次：

使用pub/sub主题订阅者模式，可以实现 1:N 的消息队列。

但在消费者下线的情况下，生产的消息会丢失，得使用专业的消息队列如**RocketMQ**等。



### Pipeline有什么好处，为什么要用pipeline？

可以将多次IO往返的时间缩减为一次，前提是**pipeline**执行的指令之间没有因果相关性。使用**redis-benchmark**进行压测的时候可以发现影响redis的QPS峰值的一个重要因素是**pipeline**批次指令的数目。



### Redis的同步机制

Redis可以使用主从同步，从从同步。第一次同步时，主节点做一次**bgsave**，并同时将后续修改操作记录到内存buffer，待完成后将RDB文件全量同步到复制节点，复制节点接受完成后将RDB镜像加载到内存。加载完成后，再通知主节点将期间修改的操作记录同步到复制节点进行重放就完成了同步过程。后续的增量数据通过AOF日志同步即可，有点类似数据库的binlog。

![image-20200728202833031](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728202833031.png)

![image-20200728202949435](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728202949435.png)



### Redis哨兵（**Redis Sentinal**）

![image-20200728203133142](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728203133142.png)



### Redis集群

![image-20200728203418965](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728203418965.png)

![image-20200728203624377](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728203624377.png)

![image-20200728203648842](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728203648842.png)

![image-20200728203704730](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728203704730.png)

![image-20200728203755139](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728203755139.png)

![image-20200728203841897](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728203841897.png)

![image-20200728203908447](C:\Users\96251\AppData\Roaming\Typora\typora-user-images\image-20200728203908447.png)



### Redis架构模式

a. 单机模式 。

 一个结点做redis服务器 ，简单 ， 但是容量有限 ，处理能力优先，并发度不高
b. 主从模式 。 

实现备份 ， 读写分离 。但是master写的压力未解决
c. 主从 + 哨兵 。 

在以前的基础上增加一个哨兵，定期检查故障 ， 自动通知应用方；如主节点崩溃，还可选一个从结点做主节点
d. 集群模式 

通过一致性哈希算法，把数据访问和修改分发给不同的集群节点 ； 分布式系统。

### Redis为什么快？

**Redis**采用的是基于内存的单进程单线程模型的 KV 数据库，由C语言编写，官方提供的数据是可以达到100000+的**QPS（每秒内查询次数）**。

- 完全基于内存，绝大部分请求是纯粹的内存操作，非常快速。它的，数据存在内存中，类似于**HashMap**，**HashMap**的优势就是查找和操作的时间复杂度都是O(1)；
- 数据结构简单，对数据操作也简单，**Redis**中的数据结构是专门进行设计的；
- 采用单线程，避免了不必要的上下文切换和竞争条件，也不存在多进程或者多线程导致的切换而消耗 **CPU**，不用去考虑各种锁的问题，不存在加锁释放锁操作，没有因为可能出现死锁而导致的性能消耗；
- 使用多路I/O复用模型，非阻塞IO；
- 使用底层模型不同，它们之间底层实现方式以及与客户端之间通信的应用协议不一样，**Redis**直接自己构建了VM 机制 ，因为一般的系统调用系统函数的话，会浪费一定的时间去移动和请求；



### Redis 和 Memcached 区别

**Redis** 支持复杂的数据结构：

**Redis** 相比 **Memcached** 来说，拥有更多的数据结构，能支持更丰富的数据操作。如果需要缓存能够支持更复杂的结构和操作， **Redis** 会是不错的选择。

**Redis** 原生支持集群模式：

在 redis3.x 版本中，便能支持 **Cluster** 模式，而 **Memcached** 没有原生的集群模式，需要依靠客户端来实现往集群中分片写入数据。

性能对比：

由于 **Redis** 只使用单核，而 **Memcached** 可以使用多核，所以平均每一个核上 **Redis**在存储小数据时比 **Memcached** 性能更高。而在 100k 以上的数据中，**Memcached**性能要高于 **Redis**，虽然 **Redis** 最近也在存储大数据的性能上进行优化，但是比起**Remcached**，还是稍有逊色。