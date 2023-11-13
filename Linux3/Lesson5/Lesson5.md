影片產生字幕
> https://github.com/smallko/test-whisper
> 老師的程式

1. 產生字幕檔用影片
2. 產生字幕用URL
3. 產生英文字幕用URL






Voice chatGPT
可以練習英文對話喔~

**跟他說一個假設的場景就可以跟他對話了**

DNS Server

>把DNS轉換成實際的IP位置

bind -> DNS Server

每台電腦都有ip位置很難記憶所以需要Domain Name 但實際上還是IP 因此需要**Dns Server**

DNS查詢

FQDN(完整網域名稱)
![picture 1](../../images/0e8c16ac374d62c292c0ab1a4b8ec638e35661a48d27ffbd3e4b407ffd35546e.png)  

![picture 3](../../images/d8ca24adcdc946a5cad8226bcdeefca47ece692b4ef5247531baf77d436f3405.png)  

ip位置很難記憶所以才需要Domain Name，但是**真正的傳輸**還需要IP

DNS 就像是一個簡單的資料庫 *domain name + ip 對應*

A紀錄
一個a > ipv4
四個a > ipv6

![picture 6](../../images/cfff46f64afc43448d68e4b785fd87e4b159de17978465521a4fdb105a14bacd.png)  
> DNS 的查詢

其他紀錄類型
![picture 4](../../images/901a5cb1faca0fd0fe0c6a0d229ffaf745a5affd348933da4fc0c1e4606c8357.png)  

根網域
特殊網域需要申請


![picture 5](../../images/6b2ab96beef914854c0fc2e93482ab888f411b9695449d171d99196b6cb5bf01.png)  
>nslookup 可以查詢Domain name 與 IP 的轉換

FQDN 是Domain name 最後要加上一點
ex. www.baidu.com.

建立Domain name server就是在建立Domain name 與 IP的對應

13台根網域伺服器

![picture 7](../../images/a488fedc1773a142168c98e3316e78e7ca11fa3fb328e4c0b8e5832d86f43c43.png)  
>DNS Server給出不一樣的答案

10.10.10.3是NQU的DNS Server

google(8.8.8.8)沒有管我們的DNS 所以會出現未經授權的回答

Linux名稱查詢工具
dig
![picture 8](../../images/46d96f08bd0944f9318ee38b8951a105b3a2e8422448da41da17061beb174aeb.png)  
> 查看別的dns位置的回應

![picture 9](../../images/8a09240c06492669f7e5429dceb6ca74e25e5156e7d12f6a441cfea87e843a42.png)  
> 管理nqu.edu.tw的 dns server是誰 是這段話的意思

## host
![picture 10](../../images/d951ba32f770d9c283dbfa2becac36b494b2c85604e6ba5e7d39dec69e217c07.png)  
> 內網與外網的ip


## 伺服器架設
### 安裝bind

![picture 11](../../images/d398eb3b3081b6daf0c0492d80039a0aac2444756768ebe5e3507e989eebfd3f.png)  
> 查看伺服器是否有被使用

![picture 12](../../images/49703a9ed27eab57bdd9391e2543e7d76ad156fc2d792e718cceaef97f6a3a95.png)  
> 先確保53 port沒有人使用 現在有人使用所以我把它砍掉了

### 安裝bind

![picture 13](../../images/14859e6ef7ef0b6c573ffdabf88c828ea744ac37518e97430ca37524ca49bf41.png)  
>安裝 bind bind-chroot bind-utils

### 更改配置檔
![picture 14](../../images/ba70f7d3d37552822776668c088c50b396504ab47d0bbdef83bc2410887360ab.png)  

**原本的設定**
![picture 15](../../images/ce93b98aa9426b9845248b7efef16a30e5d4e3825e392a2b52d09268f53cfb41.png)  

**更改後的設定**
![picture 16](../../images/beafe2fe5ef93b8235d64715a5782845d58fb4f85136a0ca7f1c76643d0581ec.png)  
> 改成any讓其他機器也能查詢到
> allow-query 裡面沒有S 我輸入錯誤
> 按esc 輸入:wq 保存退出

### 重啟named
systemctl restart named

![picture 17](../../images/50d694c4ff120639dc905a770b243314f7089b22a4e231a5dfa343ed8a5db4d7.png)  
> 作業要做好像要學校網路

### 管理網域
![picture 18](../../images/9b9154dfffee91139b0bb8d314bb6a9de1ef2a29cfeb361a2020d9d80dee0600.png)  
> 移動到named資料夾


```vi a.com.zone```
貼上以下內容 email內容要進行更改那是管理者的email
``` code
$TTL 600 ;10 minutes

@ IN SOA	@ ramy1231863.gmail.com (
		2021031803 ;serial
		10800      ;refresh
		900        ;retry
		604800     ;expire
		86400      ;minimum
		)
@		NS    dns1.a.com.
dns.com.	A     192.168.56.108
dns1		A     192.168.56.108
www		A     192.168.56.150
eshop		CNAME www
ftp		A     192.168.56.150
abc		A     192.168.56.120
```

![picture 19](../../images/199795e9594c3c4f8c8d57e598fd66b4590ea16981980657f4842b0ae1b0c4a8.png)  
>我的網域是220

所以進行了以下的更改
![picture 20](../../images/21096567d8d7d5ebf53be09b5a161d2bc141ba50c3231b6d04e8f5adacf500cb.png)  
> dns.com. 與dns1跟自己的ip位置一樣
> www ftp abc根據自己的網域來調整

編輯此檔案
```vi /etc/named.rfc1912.zones```
在最後的位置增加以下代碼:
```
zone "a.com" IN {
	type master;
	file "a.com.zone";
	allow-update { none; };
};
```

```
named-checkconf
```
> 檢查配置檔

zone "56.168.192.in-addr.arpa" IN {
	type master;
	file "56.168.192.in-addr.arpa.zone";
	allow-update { none; };
};
> 56改成你的網域 我改成 220.168.192

複製56.168.192.in-addr.arpa.zone
編輯 vi /var/named/56(更改).168.192.in-addr.arpa.zone
>56位置改成你自己的網域

```
@ IN SOA	@ ramy1231863.gmail.com (
		2021031803 ;serial
		10800      ;refresh
		900        ;retry
		604800     ;expire
		86400      ;minimum
		)

56.168.192.in-addr.arpa.    IN  NS dns1.a.com.
56.168.192.in-addr.arpa.    IN  NS dns2.a.com.

200.56.168.192.in-addr.arpa.  IN PTR www.a.com.
150.56.168.192.in-addr.arpa.  IN PTR ftp.a.com.
```
修改成這樣
![picture 21](../../images/b59d53e1583b450f20a0265070ad19bea114468e5f35a90b8139af3b8256d6a6.png)  

![picture 24](../../images/5f01c36f58e5456ae9426236ed67a700d0b1eb571d40a3c60a015daec6eb5a5c.png)  
  
> 根據你的a.com.zone 修改 ip位置對應到domain name

檢查配置檔有沒有問題
```named-checkconf```
重新啟動named
```systemctl restart named```
