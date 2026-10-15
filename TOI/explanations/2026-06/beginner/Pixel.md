# 2-像素圖放大

2026/06/8~2026/06/12 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Pixel.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Pixel.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202606/Pixel.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

將原圖的每個數字橫向重複 Q 次，組成一列後，再把整列輸出 P 次。不必建立完整放大矩陣。

## 正確性

原圖座標 (i,j) 必須填滿新圖中列 iP 到 iP+P−1、行 jQ 到 jQ+Q−1 的區塊。先重複元素再重複整列，恰好填滿這些區塊，且區塊互不重疊。

## 複雜度

時間 O(NMPQ)，與輸出大小相同；除一次讀入的輸入外，額外空間 O(MPQ)。

## 實作注意

P 放大列數，Q 放大每列的元素數；輸出數字之間需要空白。

[C++ 程式](../../../cpp/2026-06/beginner/Pixel.cpp)

[Python 程式](../../../python/2026-06/beginner/Pixel.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
