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
        - [x] Need to change the constructor to only can be created when Company struct is given. (Every stock needs company)
    - [x] Transaction history vector array
    - Methods
        - [x] AddTransactionHistory(int type, double cost)
            -[] Need to enhance AddTransactionHistory to a generic type function so that in can vbe used in Company as well
        - [] RenewStockPrice()
    - Percentage of ownership

- [] StockArray
    - [] Finish GenerateStocks()
