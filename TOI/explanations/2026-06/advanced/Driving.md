# 1-駕駛汽車

2026/06/8~2026/06/12 · 潛力組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Driving.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Driving.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Driving.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

同一格以不同方向抵達，之後的轉向費用可能不同，因此用 (格子, 上次行進方向) 作為最短路狀態。往方向 d 的鄰格移動，費用為鄰格損傷值加上「方向改變」的 0 或 1。起點四種方向都設距離 0。邊權不超過 10，採 Dial 循環桶最短路，並直接產生鄰居，省去顯式建圖。

## 正確性

任一路徑的每一步都恰好對應一條狀態邊，邊權包含且只包含該步的進格損傷與轉向費。四個起點狀態讓初始方向免費。所有邊權非負，桶按距離遞增取出狀態，與 Dijkstra 的確定距離順序相同；首次取出終點即為最小答案。

## 複雜度

V=4MN，E≤4V，最大邊權 C=10。Dial 時間 O(E+CV)=O(MN)，空間 O(MN)，另計讀入緩衝區。

## 實作注意

不能只記錄每格一個距離。桶數要大於最大邊權；遇到過期狀態需略過。此題保證起終點損傷為 0。

[C++ 程式](../../../cpp/2026-06/advanced/Driving.cpp)

[Python 程式](../../../python/2026-06/advanced/Driving.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
