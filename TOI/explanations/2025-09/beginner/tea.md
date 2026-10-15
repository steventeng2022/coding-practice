# 3-茶店

2025/09/29~2025/10/03 · 新手組

[官方題目](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/tea.pdf) · [官方參考資料](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/tea.zip) · [官方繁體中文詳解投影片](https://tpmso.k12ea.gov.tw/toi/wp-content/uploads/question/202509/tea.odp)

以下思路、正確性與複雜度以本儲存庫的 Python 版為主；C++ 檔是官方參考實作，其資料結構與常數可能不同，並未逐題證明為最快。

## 解題思路

天氣與飲料種類對應一組 5 元折扣，指定早餐或下午茶時段再折 5 元。兩組折扣獨立，符合就各扣一次。

## 正確性

第一個條件精確列出低溫熱飲與高溫冷飲兩種情形；第二個條件精確列出兩個折扣時段。依規則分別扣款，包含可疊加的情況，因此得到正確售價。

## 複雜度

時間 O(1)，空間 O(1)。

## 實作注意

C=0 是冷飲，C=1 是熱飲。時段前閉後開，10 點與 16 點不在優惠範圍。

[C++ 程式](../../../cpp/2025-09/beginner/tea.cpp)

[Python 程式](../../../python/2025-09/beginner/tea.py)

驗證以 [狀態表](../../../STATUS.md) 與 [測試報告](../../../validation.json) 為準。範例通過不等同官方評測 AC；未做跨平台效能排名，沒有宣稱全球最快。
