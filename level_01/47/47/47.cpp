#include <iostream>
#include <vector>
#include <string>

class Product {
public:
    std::string name;
    double price;

    Product(const std::string& name, double price) : name(name), price(price) {}
};

class Sale {
public:
    Product product;
    int quantity;

    Sale(const Product& product, int quantity) : product(product), quantity(quantity) {}

    double total_price() const {
        return product.price * quantity;
    }
};

int main() {
    std::vector<Product> products = {
        Product("Product1", 10.0),
        Product("Product2", 15.0),
        Product("Product3", 20.0)
    };

    std::vector<Sale> sales;
    int option;

    while (true) {
        std::cout << "1. Add sale\n2. Display sales\n3. Quit\n";
        std::cin >> option;

        if (option == 1) {
            int product_index, quantity;
            std::cout << "Choose product (0-2): ";
            std::cin >> product_index;
            std::cout << "Enter quantity: ";
            std::cin >> quantity;

            sales.push_back(Sale(products[product_index], quantity));
        }
        else if (option == 2) {
            double total_sales = 0;
            for (const Sale& sale : sales) {
                std::cout << sale.product.name << ", quantity: " << sale.quantity << ", total price: " << sale.total_price() << '\n';
                total_sales += sale.total_price();
            }
            std::cout << "Total sales: " << total_sales << '\n';
        }
        else if (option == 3) {
            break;
        }
        else {
            std::cout << "Invalid option\n";
        }
    }

    return 0;
}