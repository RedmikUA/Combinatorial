#include <iostream>
using namespace std;

class Combinatorial {
private:
    int n;
    int m;

public:
    Combinatorial() {}

    Combinatorial(int valueN, int valueM) : n(valueN), m(valueM) {}

    ~Combinatorial() {}

    int getN() const {
        return n;
    }

    int getM() const {
        return m;
    }

    void setN(int valueN) {
        n = valueN;
    }

    void setM(int valueM) {
        m = valueM;
    }

    int Count() const {
        if (getM() > getN())
            return 0;
        if (getM() == 0 || getM() == getN())
            return 1;

        int numerator = 1;
        int denominator = 1;

        for (int i = 0; i < getM(); ++i) {
            numerator *= (getN() - i);
            denominator *= (i + 1);
        }

        return numerator / denominator;
    }

    bool Compare(const Combinatorial& other) const {
        return (getN() == other.getN() && getM() == other.getM());
    }

    void Print(const Combinatorial& other) const {
        if (Compare(other)) {
            cout << "Перше та друге сполучення мають однаковi параметри." << endl;
        }
        else {
            cout << "Перше та друге сполучення мають рiзнi параметри." << endl;
        }

        int count1 = Count();
        int count2 = other.Count();

        if (count1 == count2) {
            cout << "Кiлькiсть способiв першого та другого сполучення однакова." << endl;
        }
        else if (count1 < count2) {
            cout << "Кiлькiсть способiв першого сполучення менша за друге." << endl;
        }
        else {
            cout << "Кiлькiсть способiв першого сполучення бiльша за друге." << endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "UKR");

    int n1, m1, n2, m2;
    cout << "Введiть n та m для першого сполучення: ";
    cin >> n1 >> m1;

    if (n1 < 0 || m1 < 0) {
        cout << "Помилка: введенi вiд'ємнi значення." << endl;
        return 0;
    }

    cout << "Введiть n та m для другого сполучення: ";
    cin >> n2 >> m2;

    if (n2 < 0 || m2 < 0) {
        cout << "Помилка: введенi вiд'ємнi значення." << endl;
        return 0;
    }

    Combinatorial combination1;
    combination1.setN(n1);
    combination1.setM(m1);

    Combinatorial combination2(n2, m2);

    cout << "Кiлькiсть способiв першого сполучення: " << combination1.Count() << endl;
    cout << "Кiлькiсть способiв другого сполучення: " << combination2.Count() << endl;

    combination1.Print(combination2);

    return 0;
}