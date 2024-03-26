#include <iostream>

class BankAccount 
{
    private:
        int accountNumber;
        double balance;
        double interestRate;

    public:
        BankAccount(int number, double initialBalance) 
        {
            accountNumber = number;
            balance = initialBalance;
            interestRate = 0.0;
        }

    void deposit(double amount) 
    {
        if (amount > 0) 
        {
            balance += amount;
            std::cout << "Средства успешно внесены\n";
        }
        else 
        {
            std::cout << "Ошибка: сумма должна быть положительной\n";
        }
    }

    void vivod(double amount) 
    {
        if (amount > 0) 
        {
            if (amount <= balance) 
            {
                balance -= amount;
                std::cout << "Средства успешно сняты\n";
            }
            else 
            {
                std::cout << "Ошибка: недостаточно средств на счете\n";
            }
        }
        else {
            std::cout << "Ошибка: сумма должна быть положительной\n";
        }
    }

    double getBalance() 
    {
        return balance;
    }

    double Procenti() 
    {
        double interest = balance * interestRate * (1.0 / 12.0);
        return interest;
    }

    void kofProcenti(double rate) 
    {
        interestRate = rate;
    }

    int getAccountNumber() 
    {
        return accountNumber;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount) 
    {
        if (amount > 0.0 && amount <= from.balance) 
        {
            from.balance -= amount;
            to.balance += amount;
            std::cout << "Перевод успешно выполнен\n";
            return true;
        }
        else 
        {
            std::cout << "Ошибка: недостаточно средств на счете для перевода\n";
            return false;
        }
    }
};

int main() 
{
    setlocale(LC_ALL, "RUS");
    BankAccount account1(123456, 1000.0);
    BankAccount account2(654321, 2000.0);

    account1.deposit(500.0);
    account1.vivod(200.0);
    account1.kofProcenti(0.05);

    double interest = account1.Procenti();
    std::cout << "Проценты на счете 1: " << interest << std::endl;

    double balance1 = account1.getBalance();
    double balance2 = account2.getBalance();
    std::cout << "Баланс счета 1: " << balance1 << std::endl;
    std::cout << "Баланс счета 2: " << balance2 << std::endl;

    transfer(account1, account2, 300.0);

    balance1 = account1.getBalance();
    balance2 = account2.getBalance();
    std::cout << "Баланс счета 1 после перевода: " << balance1 << std::endl;
    std::cout << "Баланс счета 2 после перевода: " << balance2 << std::endl;

    return 0;
}