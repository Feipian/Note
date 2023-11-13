Docker
輕量級虛擬化技術

vmware是重量級虛擬化技術
網路空間的隔離

先去安裝docker

> https://docs.docker.com/engine/install/centos/
> docker安裝教程
```

yum install -y yum-utils
```

```
sudo yum-config-manager \
    --add-repo \
    https://download.docker.com/linux/centos/docker-ce.repo
```

```
sudo yum install docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
```
```
systemctl start docker
```

```
systemctl status docker
```
![picture 1](../../images/1b0bef797b74f0bc8ae2a98d94e7b97cd86a75c7fe373fe97d930ca4fa1aa697.png)  

傳統虛擬化技術

docker engine使用隔離的技術
(不能有相同名字的網路卡)

docker可以實現網路直播嗎

docker c group解說:
>https://www.cnblogs.com/sammyliu/p/5886833.html

image活躍後會變成container

為甚麼image可以創造多個Container
> 跟program 與 process的關係很像

image的作用是甚麼?

docker hub可以賺錢嗎

設置一個自己存放鏡像的位置(防止被盜用)

docker對於vmware的優勢是甚麼

程式寫完就可以把image檔丟到測試工程師那兒

測試沒問題就丟給生產線
LXC
aufs

最上面的一層會在關機的時候不見??

把linux變成路由器

![picture 2](../../images/ac5868ed7f169c0d5d17be1c4f49e07d74a6c5800f93bd40fcff065247c209c0.png)  

sh -c "echo 1 > ...." 才能執行

![picture 3](../../images/986b27182f9ad3127c3a8559e4b2caaae4487b850059cc73074aab60f2c19693.png)  
> 用來看系統當中有沒有任何的鏡像

下載鏡像
![picture 4](../../images/549719e4669196aba61a69443b947701a06d065518c48dc2c80560aff91786da.png)  

可以搜尋centos
![picture 5](../../images/4f00e3b250111b91cbb70972d63638ab8a426ad61e71ae461692d60079180e37.png)  

![picture 6](../../images/07b814ee94b1d68eba0c96d23e65189cad38ddfb3c8320b01917a5c1c98a332f.png)  
> 下載時要查看安裝屬性

x86與 arm有什麼差別

![picture 7](../../images/1fd74ffd4badcee6142551a941cc99bcd76a3e220ffd69cfb6e475faf4cbbfd2.png)  
> 複製他的指令就可以下載了

![picture 8](../../images/f508247f67cf5dc32745b8109483d477b0a0330e6df1f3cceb7913b6b0915c5a.png)  
> 直接從docker hub 可以省略 repository 與 owner 從其他地方可能要寫
>

![picture 9](../../images/870026258c045eaacaf20e66c6911ae29935146871da2cb84b7ddbeba92bc60a.png)  

![picture 10](../../images/29cb30063bbec04951d6148308415c89a228f1fc84054fcd6856a587119fd1ae.png)  
> 讓docker跑起來

![picture 11](../../images/83b7c3041626f54f0519e0cb212a920e860bbb2fb91c792a6b3f8b56748378a1.png)  

> 如果 centos後面沒寫預設為 latest
>

![picture 12](../../images/613f8250668b93176a58d95e8e4820f62c54f91fa669176c818b0a1460de0440.png)  
> 查看docker有沒有在執行

![picture 13](../../images/bcb9a36b6cb3b0bc3ecc9af7a94ad8d33e6eacca96464b9485e81c0c17b6025a.png)  
> -a可以查看歷史紀錄

![picture 14](../../images/e18a2e4fdeea9900a9bbd254c4d4d19f97f00ceb5e2eb7a510067032c0e0ddac.png)  
> 可以使用名稱或著id 就可以刪除了

![picture 15](../../images/95a4bcf164025904ba50099d59a0e73232d4fad202fcab95529a012e2a41189d.png)  
> id 可以縮寫

![picture 16](../../images/add643b866c5c434583b65b359a102890ae9994290c219f166240b7c2110c04f.png)  
> 刪除鏡像

![picture 17](../../images/c8c4df88faf0d319512a9e568d091de4c8677ce6ef32f0b5d3665dcca1597533.png)  
> 可以用IMAGE ID的簡寫

![picture 18](../../images/6b2ae90f3063b9ba88e71621706063abd42aac2d0e3b4c5c1ee063548be793b2.png)  
> :後面沒加東西就會自動下載最新版本(latest)

![picture 19](../../images/4e9d3f9749e3d85fe3758c833ff020a1d51a29ac5e525417724d95760a2d647e.png)  

![picture 20](../../images/24b56335fab05b0937c4cb3e54075004297532872dc77bd13f9d1f539155c55f.png)  
> busybox只支持shell
>
![picture 21](../../images/9aed6a185bad43bc968b9563aa6443c604622c7322aaab1dbd8dc94283f6a66b.png)  
> 讓他跑sh就會一直執行，沒事做就會關閉

![picture 22](../../images/d47c44b373bb0bfcb6cb5b1463681f5fd30d3b53b898d49f8a00d9e7bd56b9cd.png)  
可以用linux連到你的docker
doceker就像獨立主機
一個linux可以開啟多個docker

![picture 23](../../images/765e28ae341466a2aa65a61a988daffeee21b73712047b3e0e07c07678ac6a0e.png)  
> 離開之後資料就會消失 所以要創建新的image檔

沒指定docker會自己給你名字

![picture 24](../../images/e2c24aa0d7cba738a7c4260311f875c1dcb9d7ce88d15eb6eb303ee7274f335d.png)  
> 自訂義名字b1

![picture 25](../../images/b5ec33565f096e9bd3b0e9c988909e7c38ee87d50a6d67e8fbe52ba99da0656b.png)  
> 創建新的image

![picture 26](../../images/ce1a606681a846deca47079815cf408be2290aab2699865948dda8306bff7166.png)  

![picture 27](../../images/14b57c51445168aa105d7a8c3374f0ac0ca3c94871a72ae18f7d7a29c698a02d.png)  
> 有了新的TAG ->0.1

![picture 28](../../images/ab6c78c3a5b4db14fdd58de3dbcd848cc8df75e3f1e72a4b4dba50eff807a1d4.png)  
> 使用剛剛建立的鏡像

![picture 29](../../images/141dfdb3db9036a46bb6f6a773465d7f99278320843104a86b3d7b72722ab349.png)  
> 把所有的docker 刪掉，正在運行的他不會刪除

![picture 30](../../images/fb5bbefca2b727cd7d37e854ebb30ce9d182eeae121e2823648040e91c94f6d4.png)  
> 加上-f正在執行的也會刪除

docker也可以下載python
![picture 31](../../images/ec6024be632c60a35c9400aec6a7ebf3eaae8db2450adb1906bd4e4515b46ee9.png)  

![picture 32](../../images/c0c16cd346e6ae5a8d245b4bcd7dd082a4b0f17776cb90ef0ae741d363cb78b6.png)  
> 創建資料夾來寫python的程式

![picture 33](../../images/a7a0e7326081587083405342d397a3f14d734c2a47cc00f2a15a87ccda685998.png)  

>把檔案丟到docker 的python去執行

![picture 34](../../images/ae543e57a34f9e8793f2750297cbdfb650704741bd313d0d5d76997f4b6eea1a.png)  

![picture 35](../../images/b3de7cd16898e84a5162a49a1f89475f2d1c9490fe9571f54a849b4bad7899b2.png)  
> 創建一個docker完成網路功能

![picture 36](../../images/94edaf4ce3e7dd6a0e1e7f295aa9bf2a262423628f6a247a6c7383a0ba2dda94.png)  

>使用2009版本

![picture 37](../../images/4bd96356870ff42e95d29f4dc98f534bc33e291a34cbae659e77a46529e9bce1.png)  
> 創建一個docker並安裝httpd


