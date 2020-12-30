# Memo

## Price deciding logic

- [] Depends on company companyValue


## Things to do

- [] Company struct
    - [x] Constructor

- [] Transaction struct
    - [x] Constructor

- [] Stock class
    - [x] Constructor
        - [] Need to change the constructor to only can be created when Company struct is given. (Every stock needs company)
    - [x] Transaction history vector array
    - Methods
        - [x] AddTransactionHistory(int type, double cost)
            -[] Need to enhance AddTransactionHistory to a generic type function so that in can vbe used in Company as well
        - [] RenewStockPrice()
    - Percentage of ownership

- [] StockArray & CompanyArray (Randomly Create)
    - [] Generate arrays all-stock & all-company at the begging of the game (Instead of DB)
        - [] Read txt files and automatically generate.
        - [] Enhanced: Fetch data from real database
