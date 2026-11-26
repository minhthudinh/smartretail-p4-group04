# SmartRetail – P4: Retail Staff Assistant

Group F02-G04 – Fundamentals of Programming (C++)

## Members & Lecturer

| Role | Name | Student ID | GitHub |
|------|------|------------|--------|
| Leader | Đinh Minh Thư | 31261028907 | minhthudinh |
| Member | Lê Bùi Minh Kha | 31261028877 | khakhavakhakha |
| Member | Nguyễn Long Kiều Thy | 31261028910 | thynguyen72 |
| Member | Thi Tuấn An | 31261028856 | mickeyan2011 |

Lecturer: Lê Văn Thể

## Specification

**Input**
- Command: `p4 <data_folder> [store_id]` (default store is S001)
- `products.csv`: product_id, name, category, brand, price, rating
- `inventory.csv`: store_id, product_id, stock
- `promotions.csv`: promo_id, product_id, discount_percent, min_quantity
- Keyboard: menu option, product ID or keyword, quantity, y/n

**Processing**
- Read the CSV files into vectors of structs. Bad lines are skipped with a warning to cerr.
- Menu loop with switch:
  - 1 – Search product by ID or keyword
  - 2 – Check inventory (OUT OF STOCK / CRITICAL / LOW STOCK / AVAILABLE)
  - 3 – Check promotions of a product
  - 4 – Checkout: cart with many lines, check stock, confirm before deducting stock
  - 0 – Exit
- Final price = price × quantity × (100 − discount) / 100. Only promotions with quantity ≥ min_quantity are used, and the highest discount is chosen.

**Output**
- Product info, stock status, promotions, cart lines and total printed on the console.
- Money is printed with thousands separators (e.g. 3,231,000 VND).
- Error messages for wrong input.

## Build & Run

```
g++ -std=c++17 -Wall -Wextra -o p4 src/*.cpp
./p4 data/sample S001
```

## Assumptions
- product_id is unique.
- The first line of each CSV file is a header.
- If a product has no stock line for the store, its stock is 0.
- Stock is only deducted in memory, the CSV files are not changed.

## Boundaries
- The program only reads and shows data, it does not save anything to files.
- It does not store any payment data (card number, CVV), it only prints the accepted payment methods.
- Only keys 1–4 are required. Keys 5 and 6 (extension) are not done yet.

## Task assignment table

| ID | Task | Function / file | Assignee | Reviewer | Flowchart | PR |
|----|------|-----------------|----------|----------|-----------|----|
| T01 | Repo skeleton, structs, README | .gitignore, PR template, src/main.cpp, README.md | Thư | Kha | not needed | #1, #5, #6 |
| T02 | Best promotion and final price (**core function**) | bestPromotion(), finalPrice() | Thư | Thy | yes | |
| T03 | Menu loop and program entry | showMenu(), main() | Thư | An | yes | |
| T04 | String and number utilities | splitLine(), toInt(), toLower(), formatMoney() | An | Thư | yes | |
| T05 | Read products.csv and inventory.csv | loadProducts(), loadInventory() | Thy | An | yes | |
| T06 | Architecture doc | docs/architecture.md | Kha | An | not needed | |
| T07 | Read promotions.csv (skip bad lines) | loadPromotions() | Kha | Thy | yes | |
| T08 | Key 1: search product | searchProduct() | Kha | Thư | yes | |
| T09 | Keys 2, 3: inventory, promotion | checkInventory(), stockStatus(), checkPromotion() | An | Kha | yes | |
| T10 | Sort and recursive binary search | sortProducts(), findProduct() | Thy | Thư | yes | |
| T11 | Key 4: checkout | checkout(), confirm() | Kha | Thy | yes | |
| T12 | Slides | docs/slides.pdf | An | Kha | not needed | |
| T13 | Test cases TC01–TC07 | tests/test_cases.md, tests/expected/ | Thy | An | not needed | |

## AI usage
- Claude (Thư): used to learn the GitHub workflow (pull requests, reviews, branch protection) and to get a suggested README structure. The content was checked with the project brief by the team.
- Claude (Kha): used to understand the requirements of the brief and to ask about C++ syntax. The code was written and checked by Kha.
- Claude (Thy): used to understand the requirements of the brief and to ask about C++ syntax. The code was written and checked by Thy.
- Claude (An): used to understand the requirements of the brief and to ask about C++ syntax. The code was written and checked by An.
