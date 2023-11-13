## 自我介紹
大家好，我叫王鴻銘，就讀金門大學資訊工程學系三年級，目前的專題是使用機器學習與時間序列方法來建構經濟項目分析平台。我負責從網路上蒐集資料集，進行文獻蒐集、資料預處理、模型蒐集、資料正規化、參數調整、評估指標選擇等工作。此外，也擁有 HTML/CSS/Javascript、Bootstrap、Ajax、Flask、Scikit-learn 和 MariaDB 等技能，負責搭建整個網站。

# 履歷表

## 個人資料

- 姓名：王鴻銘
- 學歷：學士
- 科系：資訊工程

## 專案名稱
### 建構基於機器學習與時間序列方法的加密貨幣分析平台
### 專案描述
此平台能夠讓比特幣的開盤價、黃金價格、國際石油價格來預測當日的比特幣平均值(High + Low)/2 並透過html網站來顯示比特幣的趨勢圖及預測結果。
### 使用技術
資料處理:
- Python
-  Machine Learning
-  Flask
-  Scikit-learn
  
網頁設計:
- HTML/CSS/Javascript
- bootstrap
- Ajax
  
資料庫:
- MariaDB

### 職責
- 從網路上蒐集資料集，有使用手動下載csv的方式也有透過API的方式下載數據。
- 文獻蒐集:去台灣碩博士網找尋相關文獻或是去Paperwithcode、github等網站找尋相關文獻及代碼。
- 資料預處理:
  - 更改資料期間:將蒐集來的資料切割成相同的資料期間(有些資料比較少，有些比較多)。
  - 缺失值處理:使用Scikit-learn的套件進行資料缺失值的填充
  - 訓練測試集的分割:根據相關的參考文獻分割訓練集及測試集。

<<<<<<< HEAD
- 模型蒐集:從github上面及老師提供的資料選取一些模型當做我們的使用模型。
- 資料正規化:在訓練模型之前將資料進行標準化處理，能夠幫助模型更加快速的擬合，也會使模型的預測結果更加準確。
- 參數調整: 每個模型有著不同的自訂義參數，透過調整參數能夠使模型獲得不一樣的結果，我們使用Grid Search來窮舉每一種可能值，來得到最佳的預測結果，Grid Search 可以設置交叉驗證(CV)，避免模型過擬合而不被人信任。CV設置為5，因為大多數的教學文章也使用5來當作初始值。
- 選取評估指標: 模型訓練好之後就能夠得到預測的結果，所以現在我們手上有真實的值與預測的值，那怎麼評估這個結果是否準確?那就得使用評估指標來對其進行評估了，我在文獻當中看到有人使用
  - RMSE
  - MAPE
  - MAE
  - SMAPE
  - R2
  
來當作評估指標，因此專題使用的評估指標也就是以上這五個。
=======
- 金門大學-資訊工程學系四年級
>>>>>>> 1fac2efbf976ed5d6fb91485044097f54ecf64dc

- WEB設計:Web設計本來有打算使用PHP來製作，但對於PHP的使用方式比較不熟悉，所以中途改為使用Flask來製作。也就是我們使用HTML, CSS, Javascript, Flask, MariaDB來搭建整個網站。

- 資料庫:使用者可以進行登入或註冊，註冊過的帳戶會導入MariaDB當中進行保存。
  
- AJAX請求:用戶能夠在HTML的預測頁面當中選取想要使用的預測模型，這個模型對應著一個變量的名稱(儲存著模型的名稱)，透過AJAX請求從HTML的Javascript代碼片段對Flask傳送模型名稱，Flask根據此模型名稱導入相對應模型，接著導入比特幣資料，將其分割成訓練及測試集，我們只選取測試集的部分(包含今天的比特幣開盤價，)也就是最後的20%，把他(X_test)丟到模型當中進行預測，得到預測結果，現在我們有真實值(y_test)與預測值(y_pred)，就可以回傳y_test與y_pred給剛剛的AJAX請求，此時HTML就得到比特幣真實及預測值(json格式)。
- 繪製圖表:使用Chart.js將剛剛傳進來的json檔案繪製成圖表

Github 專題項目:
> https://github.com/HongMing0603/Economic_project_forecasts/tree/Add-READEME-Main

專題影片:
> https://www.youtube.com/watch?v=Mn_ib9jtnTs

專題PPT:
> https://drive.google.com/file/d/102Yyl_qiH60gELTIwCKNR8vq_PxgjpAG/view?usp=sharing

其他項目:
> https://github.com/HongMing0603?tab=overview&from=2023-03-01&to=2023-03-31

## 學習過的技能

- 熟悉Python
- 熟悉Pandas
- 了解Pytorch
- 了解Linux (基礎)
- 了解Html
- 了解Bootstrap
- 了解Javascript
- 了解Flask
- 了解C(正在複習) 
- 了解PHP
- 了解C#
- 了解C++

### 自我評價
- 熱愛學習: 喜歡學習一些沒接觸過的知識，相信能夠與舊知識創造出新的成果。

- 很好相處
- 重視團隊合作
- 努力去解決問題

## 問題
在這份工作當中我們常用的開發工具是甚麼
會不會接觸到一些硬件相關的技術，例如嵌入式或電路。


只會實習半學年，因為還有體育課沒有修到









