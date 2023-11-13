在MVC（Model-View-Controller）架構中，控制器（Controller）是指對應於HTTP請求的組件。控制器的主要功能是接收HTTP請求，從模型（Model）中檢索所需的資料，然後將資料傳遞給視圖（View）進行顯示。控制器通常包含一些方法，每個方法都對應一個HTTP請求，並負責處理該請求。

在PHP中，控制器通常是一個類（Class），並包含一些公共方法。以下是一個簡單的PHP控制器範例：
```php
php
Copy code
<?php
class UserController {
    public function index() {
        // 處理 HTTP GET 請求
        // 檢索用戶數據
        // 將數據傳遞給視圖進行顯示
    }
    
    public function store() {
        // 處理 HTTP POST 請求
        // 解析用戶提交的數據
        // 驗證數據的合法性
        // 將數據保存到數據庫中
        // 轉發或重定向到相應的頁面
    }
    
    public function update() {
        // 處理 HTTP PUT 或 PATCH 請求
        // 解析用戶提交的數據
        // 驗證數據的合法性
        // 更新數據庫中的數據
        // 轉發或重定向到相應的頁面
    }
    
    public function destroy() {
        // 處理 HTTP DELETE 請求
        // 從數據庫中刪除數據
        // 轉發或重定向到相應的頁面
    }
}
```
上面的範例中，UserController類包含了index、store、update和destroy這些方法。index方法處理HTTP GET請求，store方法處理HTTP POST請求，update方法處理HTTP PUT或PATCH請求，destroy方法處理HTTP DELETE請求。每個方法都對應一個HTTP請求，並負責處理該請求。