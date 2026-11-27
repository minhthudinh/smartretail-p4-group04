// smartretail.h - shared structs and function prototypes (T01)
// Every .cpp file includes this header. Do not define functions here.
#ifndef SMARTRETAIL_H
#define SMARTRETAIL_H

#include <string>
#include <vector>
using namespace std;

// ===== Structs (one per CSV record) =====
struct Product {
    string productId;
    string name;
    string category;
    string brand;
    long long price;   // VND
    double rating;
};

struct Inventory {
    string storeId;
    string productId;
    int stock;
};

struct Promotion {
    string promoId;
    string productId;
    int discountPercent;   // 0-100
    int minQuantity;
};

// ===== T04 - utils.cpp (An) =====
vector<string> splitLine(const string& line, char separator);
bool toInt(const string& text, int& value);          // false if not a number
string toLower(const string& text);
string formatMoney(long long amount);                 // 3590000 -> "3,590,000"

// ===== T05 - load_data.cpp (Thy) =====
bool loadProducts(const string& folder, vector<Product>& products);
bool loadInventory(const string& folder, vector<Inventory>& inventory);

// ===== T07 - load_promotions.cpp (Kha) =====
bool loadPromotions(const string& folder, const vector<Product>& products,
                    vector<Promotion>& promotions);

// ===== T02 - pricing.cpp (Thu) - core function =====
int bestPromotion(const vector<Promotion>& promotions, const string& productId,
                  int quantity);                      // index or -1
long long finalPrice(long long price, int quantity, int discountPercent);

// ===== T03 - main.cpp (Thu) =====
void showMenu(const string& storeId);

// ===== T08 - search.cpp (Kha) =====
void searchProduct(const vector<Product>& products,
                   const vector<Inventory>& inventory,
                   const vector<Promotion>& promotions, const string& storeId);

// ===== T09 - inventory_promotion.cpp (An) =====
int getStock(const vector<Inventory>& inventory, const string& storeId,
             const string& productId);                // 0 if no line found
string stockStatus(int stock);
void checkInventory(const vector<Product>& products,
                    const vector<Inventory>& inventory, const string& storeId);
void checkPromotion(const vector<Product>& products,
                    const vector<Promotion>& promotions);

// ===== T10 - sort_search.cpp (Thy) =====
void sortProducts(vector<Product>& products);         // bubble or selection sort
int findProduct(const vector<Product>& products, const string& productId,
                int low, int high);                   // recursive, index or -1

// ===== T11 - checkout.cpp (Kha) =====
void checkout(const vector<Product>& products, vector<Inventory>& inventory,
              const vector<Promotion>& promotions, const string& storeId);
bool confirm(const string& question);

#endif
