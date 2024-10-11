#pragma once
#include <vector>
#include "iostream"

template <typename T>
class SingletonObject {
    protected:
        SingletonObject() {}
        friend class SingletonDestroyer;
        virtual ~SingletonObject() {}
        static SingletonObject *_instance;
        static std::vector<T> _list;
    private:
        SingletonObject(const SingletonObject&) {};
        SingletonObject& operator=(const SingletonObject&) {};
        static SingletonDestroyer _destroyer;
    public:

        static SingletonObject *get_instance()
	    {
		    if (_instance == nullptr)
			    _instance = new SingletonObject();
                _destroyer.setSingleton(_instance);
		    return _instance;
	    }

        static void    add(const T& item) {
            _list.push_back(item);
        }

        static void    remove(const T& item) {
            typename std::vector<T>::iterator it = _list.begin();
            for (; it != _list.end(); ++it) {
                if (*it == item) {
                    _list.erase(it);
                    break;
                }
            }
        }

        static std::vector<T> get_list() {
            return _list;
        }

        T operator[](int index)
        {
            if (index < 0 && index >= _list.size())
                throw std::out_of_range("Index out of range");
            return _list[index];
        }
};

template <typename T>
SingletonObject<T>* SingletonObject<T>::_instance = nullptr;

template <typename T>
SingletonDestroyer<T> SingletonObject<T>::_destroyer;

template <typename T>
std::vector<T> SingletonObject<T>::_list;

template <typename T>
class SingletonDestroyer {
 public:
    SingletonDestroyer(SingletonObject<T> *s) {
        _singleton = s;
    }

    ~SingletonDestroyer() {
        delete _singleton;
    }

   void setSingleton(SingletonObject<T> *s) {
        _singleton = s;
    }

 private:
   SingletonObject<T>* _singleton;
};
