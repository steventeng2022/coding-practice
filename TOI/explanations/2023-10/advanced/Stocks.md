# 1-股票交易

2023/10/23~2023/10/27 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/Stocks.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/Stock.odp) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202310/Stock.odp)

## 解題思路

以最小堆保存尚未達標的買入日，鍵值為當日價格加 K。掃描賣出日時，將所有門檻不高於當日價格的買入日取出，答案設為今天；最後才加入今天的買入紀錄。

## 正確性

交易日由早到晚掃描，等待堆中的紀錄在更早日期都未達標，因此第一次被取出的日期就是最早合法賣出日。最小堆確保所有今天可達標的紀錄都會被處理，堆頂未達標時更高門檻也不會達標。

## 複雜度

時間 O(N log N)，空間 O(N)。

## 實作注意

先處理賣出再加入今日買入，避免使用同一天；未被取出的日子輸出 −1，日期從 1 起算。

[C++ 程式](../../../cpp/2023-10/advanced/Stocks.cpp)

[Python 程式](../../../python/2023-10/advanced/Stocks.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
