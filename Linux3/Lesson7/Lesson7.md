讓docker在背景執行![picture 1](../../images/e457a710c44823485710caecae22e7642106b0ffdfb84e2568dc765075b4b015.png)  

systemctl 是一些代碼的封裝![picture 2](../../images/aab4136dde5d53460cf1e26aca5487e7b8bdc2e1b19b3863766f62a69be022d3.png)  

```
docker run -d -p 8000:80 centos:web /usr/sbin/apachectl -DFOREGROUND
```
> 把localhost 的8000 port 綁定docker的80 port


![picture 3](../../images/dea3095a01811d8f4a7d4d4acb2e331c35d42485fd985931ae783760047568df.png)  
> host綁定docker

![picture 4](../../images/2a3a8c6a8ea5433174b471db3cca44d62d542f65dbe7edb570c24a0541bc42cf.png)  
> 測試8000是不是有人使用

![picture 5](../../images/69e21d7541cecaf541f78474628cececc355cfa4d8bfc5b197b61402ea0bfe05.png)  
> 本地端任意一個8000 port 會指向docker的80port

![picture 6](../../images/bc67a125a3e41e8794e6ccc2192bca71c0666c2b6e5535dc10f89bfe323ab38b.png)  

鏡像打包
![picture 7](../../images/2ef1a737afb746213a783be64d4cda60182b4f146ffc7f4d6a5c170256f81c6e.png)  
> 可以從外地下載docker的壓縮檔來安裝docker

導出鏡像
![picture 8](../../images/db74a257661494aebad528da441ca461be81c9ed4283792a95bd6a3081de5890.png)  

![picture 9](../../images/17eaf259ba230f72196edba76c697e6d4bf328ff32e838ea1336c78576678d68.png)  
> 使用id執行相對應docker

![picture 10](../../images/1e01451ca2344a1a2a48c9f6b36f5a6f6da808c9356665f1b3faa6fe7861e7f4.png)  
> 在docker 的centos建立網站

另一種方式:
![picture 11](../../images/1288df375b981bcc9fbdfd1d52668916a98027f5df2cade2008022cabc788739.png)  

![picture 13](../../images/898a1ddeeb8f1944ef05a951dffb311a66d66a627db4ad6671ac9ca8ab0ba607.png)  


![picture 12](../../images/1279bfee55be39ddb4a5f07169edaefb7a9336f360bd9518150027871d88cdc3.png)  

![picture 14](../../images/e1dcf17b114126b5f069b5e559836dc37b9fb2d85b043e27cd7ba4e94ea1a229.png)  
> 修改名稱及port就能夠快速創造出多個docker 
> 應該有更快的方式，使用腳本?

![picture 15](../../images/dbfe5a6cf987c09ff85d80068e1caf88ec2bee87eea8fa9c3e5d2925fa7d8e83.png)  
> 把所有docker先砍掉 因為要使用腳本來執行創建

![picture 16](../../images/272cb0994aca75603aa79b9c37620877ea4eec2b783e7e84c2c49cec874357c5.png)  
> 創建一個docker_create的bash

```
#!/usr/bin/bash

for i in {1..5}
do
    portno=`expr 8000 + $i`
    docker run -d -p $portno:80 -v /home/user/myweb:/var/www/html centos:web /usr/sbin/apachectl -DFOREGROUND
done
```
執行腳本(使用bash)
![picture 18](../../images/c4804f7d17390cfd5655061d02dd9cb89c364f86f7a0bc50a2c8c32fc3e57960.png)  



![picture 17](../../images/f920f0eb7ff21a2c96fa822c790c80a5485032695f0e66cde4d11070e9ca8586.png)  
> 通常會建置一個load balancer來分配負載請求?


haproxy可以達成load balance


![picture 19](../../images/dca4446588f8309fba83617370911dc590a2ef4a19df80f361aa7f22d38f5559.png)  
> 安裝haproxy與ssl

![picture 20](../../images/1a4a35a65aaa9ea97629701bb86591adfc73162cbe5a2978d5d8109a91922a23.png)  
> 移動到haproxy的conf

>https://github.com/FUYUHSUAN/note/blob/master/110-2%E8%87%AA%E5%8B%95%E5%8C%96%E9%81%8B%E7%B6%AD/2022_03_16/note.md

貼上學姊的代碼
![picture 21](../../images/88e6267bc749408af0af3007c4a1b0cb6a4f519b77f6571a46b040b3cc3afce4.png)  

```
defaults
  mode http
  timeout client 10s
  timeout connect 5s
  timeout server 10s
  timeout http-request 10s

frontend myfrontend
  bind 0.0.0.0:8111
  default_backend myservers

backend myservers
  balance roundrobin
  server server1 192.168.220.145:8001 check
  server server2 192.168.220.145:8002 check
  server server3 192.168.220.145:8003 check
  server server4 192.168.220.145:8004 check
  server server5 192.168.220.145:8005 check
```
> 我進行了修改

在上面的配置檔案中，我們將伺服器（server）的定義更改為使用本地地址和 Docker 容器的端口。例如，127.0.0.1:8001 代表容器的 IP 地址為 127.0.0.1（也就是本地地址），而容器的端口為 8001。然後使用輪詢（roundrobin）平衡負載方式來分發流量到這五個 Docker 容器，並檢查這些容器是否可用（check）。

如果您已經將 HAProxy 的配置檔案保存在主機上，您可以使用以下命令在 Docker 上運行 HAProxy 容器：

```
docker run -d -p 8111:8111 --name haproxy -v /etc/haproxy/haproxy.cfg:/usr/local/etc/haproxy/haproxy.cfg haproxy:latest
```
![picture 32](../../images/d8c7bb45950b20a8be0717789846422e439c171f4596bf0bd8e807728cceab76.png)  
> 遇到問題

解決方法:
> https://blog.csdn.net/qq_63698117/article/details/128917454


重新執行
```
docker run -d -p 8111:8111 --name haproxy -v /etc/haproxy/haproxy.cfg:/usr/local/etc/haproxy/haproxy.cfg haproxy:latest
```

執行 create docker遇到問題
![picture 33](../../images/4f02b802a61f6fdef7ee226233ef06a6fe06cdca5b8375563dc96a017d128691.png)  

![picture 34](../../images/62417b0de5a9e251fe4fba92cf3348fe42f048a2496bd11963b43a4aa06c4fd6.png)  
> 重新啟動docker就能夠執行 sh檔了

```
[root@localhost user]# docker run -d -p 8111:8111 --name haproxy -v /etc/haproxy/haproxy.cfg:/usr/local/etc/haproxy/haproxy.cfg haproxy:latest
86a6813a28778b1219272002a771282fe5dd06c114350a9002d5b3dc8405066d
```

```systemctl start haproxy```

![picture 22](../../images/ae5f8011f8b869eeb91eb1c450b7612b4711143a3fef5e901904002afa064ed0.png)  
看他有沒有成功運行

![picture 23](../../images/9345926946d324a685fd3c6353af4aa40bb813c656a1cf1bc268bbd804c9a938.png)  
> 創建5個資料夾

![picture 25](../../images/833e6f3a2a7da48291e8c66798b91781996b8a50ee2b264dee376d4730593406.png)  


![picture 24](../../images/ed3930a78c3b267215b65fdcdee9533c22f63e3a37969512099d98fb81a2a90c.png)  
> 修改create sh檔
> 就能夠展示loader balance的效果了

修改haproxy
```
    server  app3 127.0.0.1:5003 check
    server  app4 127.0.0.1:5004 check

defaults
  mode http
  timeout client 10s
  timeout connect 5s
  timeout server 10s
  timeout http-request 10s

frontend myfrontend
  bind 0.0.0.0:81
  default_backend myservers

backend myservers
  balance roundrobin
  server server1 192.168.220.149:8001 check
  server server2 192.168.220.149:8002 check
  server server3 192.168.220.149:8003 check
  server server4 192.168.220.149:8004 check
  server server5 192.168.220.149:8005 check                                    
```

```bash create_docker_httpd.sh```

![picture 31](../../images/c2d922c1bf3990edd773735d158002c5734f5ecde1492b93254b59709912df1a.png)  

先刪除所有docker
```docker rm -f `docker ps -a -q` ```

創建一個docker連接到haproxy
```
docker run -p 81:81  -d --name haproxy-master -v /etc/haproxy/haproxy.cfg:/usr/local/etc/haproxy/haproxy.cfg --privileged=true haproxy
```
> 我的81 port 已經在使用了修改為別的port -> haproxy.cfg也要修改

執行 create_docker.sh
![picture 35](../../images/2519d8032aeea5b9c347cc34165b2c4050c18673bea1095b09d13320f965becf.png)  





雲端備份

![picture 26](../../images/d52b38ec8e79b7c595006a77048575c81fbe40f65dea16341d52507c4d0abbb2.png)  
> a35是id 給他一個新的標籤名稱 要更改是因為要符合它上傳的規定?

以下是我的 /前面要是你的docker username




![picture 36](../../images/a41dc5553110889a8fe55d4fc54a16c1697191605ded1d26199db914da8ca798.png)  
> login前請驗證信箱

![picture 37](../../images/5c2acbc719f0163faf503d940c9bdacce903ddaf0e62dc330bd3b8de96bcc29f.png)  
> login時出現error

修改
```vim /etc/resolv.conf```

![picture 38](../../images/19c2b80de74f8d928015349aa49fb1c9f8e449e631ca4060fbdb614a7f12cfd1.png)  

之後就成功登入了

![picture 27](../../images/4cba53ccbe86841372ff77729d5f38a38a788c61ca41adb7df59820b9f259337.png)  
> 登入docker

![picture 28](../../images/0671c45515cc2a256f2645dc3eacf7821ffb7819d0d7938755f3ef34252092ea.png)  
> 把鏡像推送到雲端

![picture 39](../../images/876fc39664aeb531bd54e8e47c14c3e2e80b205ff2b8200495bfda9ee2285496.png)  
> 成功推送!!

![picture 40](../../images/2231dbb75da9e37520618d3e49e56b20edde5cd17c4d7c35e9fc7922069ebe87.png)  


下載docker

![picture 41](../../images/021ab2ba74aafa95e071c4fe7c93b1cca7de818e9adf6554c63d8aed335ff50c.png)  
> 下載成功


![picture 29](../../images/c85479f5ce8970c1b6e41760cbe2a63c63ad07252bf21c704ffdb91c666dd5dd.png)  
>先刪除因為我們要測試從網路下載

rmi失敗可能是image在執行

![picture 30](../../images/fd0055d200fc20e87f5f2e5a463395ff5d0a83108839173351de97e424d1e4cb.png)  
> 貼上docker hub的網址


正確版本:
先關閉防火牆跟selinux(害了我好久!!!)

```systemctl stop firewalld```
```setenforce 0```

建立五個網頁伺服器網頁內容分別為web1~web5
prepare_web.sh
```
#!/usr/bin/bash

for i in {1..5};
do 
    mkdir -p myweb$i
    cd myweb$i
    echo web$i > hi.htm
    cd .. 
done
```
執行
```bash prepare_web.sh```

編輯掛載資料夾docker_httpd_setup.sh gedit docker_httpd_setup.sh

```
 #!/usr/bin/bash

for i in {1..5}
do
    portno=`expr 8000 + $i`
    docker run -d -p $portno:80 -v /home/user/myweb$i:/var/www/html centos:web /usr/sbin/apachectl -DFOREGROUND
done
```


打開docker: systemctl start docker

刪除所有docker
```docker rm -f `docker ps -a -q` ```

執行docker_httpd_setup.sh
```bash docker_httpd_setup.sh```

安裝haproxy
```yum install haproxy```

```cd /etc/haproxy/```
```vim haproxy.cfg```
寫入以下內容
```
defaults
  mode http
  timeout client 10s
  timeout connect 5s
  timeout server 10s
  timeout http-request 10s

frontend myfrontend
  bind 0.0.0.0:8080 (任意改妳要的port[localhost])
  default_backend myservers

backend myservers
  balance roundrobin
  server server1 192.168.48.171(vitual machine ip):9001 (docker對應到的虛擬機port)
  server server2 192.168.48.171:9002
  server server3 192.168.48.171:9003
  server server4 192.168.48.171:9004
  server server5 192.168.48.171:9005
```

打開電腦的瀏覽器
打上你虛擬機的ip ex(192.168.48.171)
```192.168.48.171:8080```
> 8080對應到bind的 port

享受loader balance吧~



