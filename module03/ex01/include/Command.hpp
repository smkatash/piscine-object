#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <iostream>
#include <map>

/* Runtime override with virtual vs Compile time*/
class Command {
    protected:
        int _id;
        std::string _date;
        std::string _client;
        std::map<std::string, double>  _articles;

    public:
        Command(int id, const std::string& date, const std::string& client): _id(id), _date(date), _client(client) {}
        virtual ~Command() {}

        int get_id() { return this->_id; }

        virtual double get_total_price() {
            double sum = 0;
            std::map<std::string, double>::const_iterator it = this->_articles.begin();
            for (; it != this->_articles.end(); ++it) {
                sum += it->second;
            }
            return sum;
        }

        void				add_article(std::string item, double price) {
			this->_articles.insert(std::make_pair(item, price));
		}
        void				list_articles() {
			std::cout << "Command: " << this->_id;
            if (this->_articles.size() == 0) {
                std::cout << " - No items."<< std::endl;
                return ;
            }
            std::cout << std::endl;
            std::map<std::string, double>::iterator it = this->_articles.begin();
            for (; it != this->_articles.end(); ++it) {
                std::cout << "Item: " << it->first << "Price " << it->second << std::endl;
            }
		}
		
		void				delete_article(std::string item) {
			this->_articles.erase(item);
		}
		
};

#endif
