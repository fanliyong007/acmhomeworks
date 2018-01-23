CREATE TABLE LXJ_categories
(
    CategoryID INT PRIMARY KEY AUTO_INCREMENT,
    CategoryName VARCHAR(22) NOT NULL UNIQUE,
    Descriptions VARCHAR(22)
)

CREATE TABLE LXJ_books
(
    BookID CHAR(4) PRIMARY KEY,
    BookName VARCHAR(50) NOT NULL,
    CategoryID INT NOT NULL,
    Published DATETIME,
    Price DECIMAL(10,2),
    Pic VARCHAR(100),
    FOREIGN KEY (CategoryID) REFERENCES LXJ_categories(CategoryID)
)

SELECT BookName,Authors,Price FROM LXJ_books;