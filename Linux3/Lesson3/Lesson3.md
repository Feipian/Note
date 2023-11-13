WebDav

使用https會比較安全
虛擬機要坐鏡像
安裝第三方庫
>yum install epel-release

安裝httpd

測試是否有支援WebDav
![picture 1](../../images/48e50a13c2b259b756624da6592f1569efa88460ed9dc2deb73c86eabf6c445d.png)  
![picture 2](../../images/b62cb8667d9d0cc067b8a837edc2ecb3f8e292e93f533d8899852335d6126eff.png)  

![picture 3](../../images/28abab8b919237db2e04d68e7234743e493a80c22ee9c6e7a4b29d22d9925cf2.png)  

建立資料夾
![picture 4](../../images/609d3bfb11eb0318c5cddf317b04f4711e1c397ae207bca5a02f9904e8dc3b7f.png)  

更改權限
![picture 6](../../images/6c7d74b5fbc5cc975eab0235416bf89aa11f1504f141044690ea16c09c50830c.png)  

編輯webdav.conf
![picture 1](../../images/50b178f352de6600de67a89947946c7b5d126d29a2b762645b59d4b62d042b84.png)  


```
DavLockDB /var/www/html/DavLock
<VirtualHost *:80>
    ServerAdmin webmaster@localhost
    DocumentRoot /var/www/html/webdav/
    ErrorLog /var/log/httpd/error.log
    CustomLog /var/log/httpd/access.log combined
    Alias /webdav /var/www/html/webdav
    <Directory /var/www/html/webdav>
        DAV On
        #AuthType Basic
        #AuthName "webdav"
        #AuthUserFile /etc/httpd/.htpasswd
        #Require valid-user
        </Directory>
</VirtualHost>
```

重新啟動
```
systemctl restart httpd
```

於WebDav建立a,b,c,d 文件
```
touch {a..d}
```

![picture 7](../../images/67013d52c4a98ccdeb20ba628f12502c01c51cfc051aa77208728e26f7230e62.png)  

![picture 8](../../images/0539b4e1e47a7ec685e4b502c6c647d809875630e14b57d82c678b22e268f4c2.png)  
> 作業圖片

新增網路磁碟機
![picture 9](../../images/7c79a242d655ca8880dec73191aed2caa21fd028948ed9244fb91057e52e7ed7.png)  

![picture 10](../../images/15b40fc362fa9faf31bcaf3528c192ccc8a952025c2cf7019de931f17f9ea086.png)  

貼上你的位置

![picture 11](../../images/363b4f59795179260e3c72d962df5fa91a5a0c0b6efeee8fdca205e33826286d.png)  
> 無法創建資料....
>

![picture 12](../../images/9b08c0273afa181d5896a8eb9ec851aeedf546533334b4eb08079b20a3a95f34.png)  

```
cat <<EOF >settings.conf
> name: Alan
> age: 18
> EOF
```
> 創建一個settings.conf檔案

![picture 13](../../images/ebfc5019428be2163e3add2aeac3e8feb69e5ae38d5a8f6a3184c552f7962930.png)  
> 作業圖片

![picture 14](../../images/34291a8b8588c9b16a89e5359c0658dd572a02d961b252627e3be43bb8a9acd5.png)  
> 全部取代 settings.conf是檔案

![picture 15](../../images/52815b1a6f5b89294fcd7d730389289d61b47415124428df019206d9de0229fc.png)  
> only show on the screen

![picture 16](../../images/4089f9de91afaadab00e36755fccbf9b7a56483457cfaa35ff737d6b9d1f396c.png)  
> 加上i 就會改掉裡面的內容

![picture 17](../../images/9ce9ddba47a4bff3e4b4f3f3280b803209164ae9c930b5bbe6f34034bc5840b0.png)  
> 把abc d 改成 a bcd
> 作業圖片


