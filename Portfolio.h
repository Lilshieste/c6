#ifndef Portfolio_h
#define Portfolio_h

#include <string>
#include <exception>
#include <unordered_map>
#include <vector>
#include "boost/date_time/gregorian/gregorian_types.hpp"

class InvalidPurchaseException: public std::exception {
};

class InvalidSellException: public std::exception {
};

// START:PurchaseRecord
struct PurchaseRecord {
   PurchaseRecord(unsigned int shares, const boost::gregorian::date& date) 
   : Shares(shares) 
   , Date(date) {
   }
   unsigned int Shares;
   boost::gregorian::date Date;
};

class Portfolio {
public:
   static const boost::gregorian::date FIXED_PURCHASE_DATE;
   bool IsEmpty() const;
// START:defaultedDate
   void Purchase(
         const std::string& symbol, 
         unsigned int shares,
         const boost::gregorian::date& transactionDate
            =Portfolio::FIXED_PURCHASE_DATE);
// END:defaultedDate
   void Sell(const std::string& symbol, unsigned int shares);
   unsigned int Shares(const std::string& symbol) const;
   std::vector<PurchaseRecord> Purchases(const std::string& symbol) const;

private:
   std::unordered_map<std::string, unsigned int> holdings_;
   std::vector<PurchaseRecord> purchases_;
};
// END:PurchaseRecord
#endif
