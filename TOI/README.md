# TOI 推廣歷屆試題解答

資料來源：[TOI 官方歷屆試題](https://tpmso.k12ea.gov.tw/toi/index.php/tasks/)，核對日期 2026-10-16。

涵蓋題單為 2019–2026 年所有組別：新手組 135 題、潛力組 135 題、新手同好會 64 題。

## 完成進度

題目 334 題；C++ 程式 333 份；Python 程式 56 份；獨立繁體中文詳解 56 篇。

**這是尚未完成的解答集。** 全題單共 334 題，其中 Robot 依使用者指示略過，不列入待完成數量；其餘 333 題已有 C++ 程式，仍有 277 題缺 Python 實作與本儲存庫獨立詳解。沒有把官方參考程式一律當成最優解，也沒有宣稱所有程式已通過官方評測或效能排名。缺項逐題列在 [狀態表](STATUS.md)，機器可讀版本為 [manifest.json](manifest.json)。

已完成雙語與獨立詳解的部分：2025、2026 年共 54 題，加上 2023-10 股票交易與 2020-04 迷宮逃離，共 56 題。

## 資料夾

- [cpp](cpp)：GNU++17 單題程式，按日期與組別分類。保留官方程式來源；重新實作的版本在 manifest 標記 authored。
- [python](python)：Python 3 單題程式；每份都是獨立演算法實作，使用標準函式庫。
- [explanations](explanations)：56 篇繁體中文獨立詳解，包含思路、正確性、複雜度與注意事項；其餘為 277 頁待完成的來源索引，以及 1 頁依使用者指示略過的 Robot 紀錄。
- [tests](tests)：官方範例、重現驗證工具與小資料暴力對拍。

路徑範例：`cpp/2026-06/beginner/Laser.cpp`、`python/2026-06/beginner/Laser.py`、`explanations/2026-06/beginner/Laser.md`。

組別代碼：`beginner` 新手組、`advanced` 潛力組、`club` 新手同好會。`YYYY-MM-club` 表示該月同好會，與一般月賽分開。

## 執行

```sh
g++ -std=gnu++17 -O2 -pipe cpp/2026-06/beginner/Laser.cpp -o laser
./laser < input.txt
python python/2026-06/beginner/Laser.py < input.txt
```

C++ 官方程式使用 GNU 擴充或 `bits/stdc++.h`，建議使用 GCC。Python 不需安裝第三方套件。

## 驗證

本次 C++ 編譯通過 333/333 份；有雙語程式的 56/56 題通過共 145 組官方範例（按空白分詞比較）。另執行 2418 組小資料或窮舉對拍，涵蓋 17 個較複雜演算法。詳細結果見 [validation.json](validation.json)。

本機為 Windows、Clang 22.1.2、GNU++17、MSVC 標準函式庫；編譯時以相容標頭提供 `bits/stdc++.h`。Python 版本為 3.12.14。這些是本機驗證，沒有登入 TOI 評測系統提交，亦未完成全部題目的極限資料效能測試。

重跑雙語範例（需要 GCC 與 Python 3）：

```sh
python tests/verify.py --language both
python tests/oracles.py
```

可用 `--language python` 只測 Python，`--all-reference` 額外編譯參考程式。

## 缺漏與來源

**已略過：2020-08 新手同好會「居家管理機器人（Robot）」。** 官方題目、參考程式與詳解連結均未成功取得；依使用者於 2026-10-16 的指示略過，不補寫 C++、Python 或獨立詳解，也不列入待完成數量。保留題目索引與原始連結供查考。2026-03「選舉」與 2025-12「塗鴉連線」在官方頁沒有可點擊的詳解投影片，本儲存庫已另撰解說。

部分官方連結包含舊主機、遺漏 `/toi` 或多餘反斜線，已核對同站正確路徑；manifest 同時保留原始索引網址。題目 PDF 與投影片以連結引用，不將大型檔案加入 Git。

官方參考程式的權利歸原作者；本儲存庫保留逐題來源，不另替官方資料宣告授權。2023-12 同好會「間諜」另修正了初始化變長陣列造成的編譯錯誤，詳見 manifest 的 source_adjustments。詳見 [來源說明](SOURCES.md)。

## 全題索引

請從 [完整狀態表](STATUS.md) 依年度、組別與題名開啟程式或題解。
