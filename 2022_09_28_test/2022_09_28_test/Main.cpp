#include <iostream>
#include <memory>
#include <mutex>

#include <iostream>
using namespace std;
class Singleton
{
private: //对类内开放，对类外不开放
    static Singleton* singleton; //定义指针
    Singleton()
    {
        cout << "Singleton的构造" << endl;
    }
public:
    //定义一个公有接口，返回本类对象的指针
    static Singleton* getInstance()
    {
        return singleton;
    }
    void showInfo()
    {
        cout << this << endl;
    }
    //把编译器自动提供的拷贝构造与 = 号运算符重载移除
    Singleton(const Singleton& other) = delete;
    void operator = (const Singleton& other) = delete;
};

Singleton* Singleton::singleton = new Singleton;
int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    Singleton* s3 = Singleton::getInstance();

    cout << s1 << "," << s2 << "," << s3 << endl; //s1、s2和s3 地址一样
    return 0;
}
//class Chairman
//{
//public:
//	void print()
//	{
//		std::cout << "对象调用" << std::endl;
//	}
//private:
//	Chairman()
//	{
//		std::cout << "创建类" << std::endl;
//	}
//public:
//	static Chairman* singleman;
//};
//Chairman* Chairman::singleman = new Chairman;
//
//int main()
//{
//
//	return 0;
//}
//class Singleton
//{
//public:
//	~Singleton()
//	{
//		std::cout << "destructor called!" << std::endl;
//	}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//	static Singleton& get_instance()
//	{
//		static Singleton instance;
//		return instance;
//	}
//private:
//	Singleton()
//	{
//		std::cout << "constructor called!" << std::endl;
//	}
//};
//
//int main()
//{
//	Singleton& instance = Singleton::get_instance();
//	return 0;
//}
//class Singleton
//{
//public:
//	typedef std::shared_ptr<Singleton> Ptr;
//	~Singleton()
//	{
//		std::cout << "destructor called!" << std::endl;
//	}
//	Singleton(Singleton&) = delete;
//	Singleton& operator = (const Singleton&) = delete;
//	static Ptr get_instance()
//	{
//		if (m_instance_ptr == nullptr)
//		{
//			std::lock_guard<std::mutex> lk(m_mutex);
//			if (m_instance_ptr == nullptr)
//			{
//				m_instance_ptr = std::shared_ptr<Singleton>(new Singleton);
//			}
//		}
//		return m_instance_ptr;
//	}
//private:
//	Singleton()
//	{
//		std::cout << "constructor called!" << std::endl;
//	}
//	static Ptr m_instance_ptr;
//	static std::mutex m_mutex;
//};
//
//Singleton::Ptr Singleton::m_instance_ptr = nullptr;
//std::mutex Singleton::m_mutex;
//
//int main()
//{
//	Singleton::Ptr instance = Singleton::get_instance();
//	return 0;
//}

//单例模式，全局只有一个实例，同时禁止用户声明并定义实例，构造函数是私有的
//禁止赋值和拷贝
//线程安全
//用户通过接口获取实例，使用static类成员函数

//懒汉模式:直到使用时才实例化对象，也就是说直到调用get_instance()方法的时候才new一个单例的对象。
// 
//class Singleton {
//private:
//    Singleton() 
//    {
//        std::cout << "constructor called!" << std::endl;
//    }
//    Singleton(Singleton&) = delete;        //禁止赋值构造
//    Singleton& operator=(const Singleton&) = delete;       //禁止拷贝构造
//    static Singleton* m_instance_ptr;
//public:
//    ~Singleton() {
//        std::cout << "destructor called!" << std::endl;
//    }
//    static Singleton* get_instance() {
//        if (m_instance_ptr == nullptr) {
//            m_instance_ptr = new Singleton;
//        }
//        return m_instance_ptr;
//    }
//    void use() const { std::cout << "in use" << std::endl; }
//};
//
//Singleton* Singleton::m_instance_ptr = nullptr;
//
//int main() {
//    Singleton* instance = Singleton::get_instance();
//    //Singleton* instance_2 = Singleton::get_instance();
//    instance->use();
//
//
//    
//    return 0;
//}
//class Singletion
//{
//private:
//	Singletion()
//	{
//		std::cout << "constructor called!" << std::endl;
//	}
//	Singletion(Singletion&) = delete;//禁止赋值构造
//	Singletion& operator=(const Singletion&) = delete;
//	static Singletion* m_instance_ptr;
//public:
//	~Singletion()
//	{
//		std::cout << "destructor called!" << std::endl;
//	}
//	static Singletion* get_instance()
//	{
//		if (m_instance_ptr == nullptr)
//		{
//			m_instance_ptr = new Singletion;
//		}
//		return m_instance_ptr;
//	}
//	void use() const
//	{
//		std::cout << "in use" << std::endl;
//	}
//};
//
//int main()
//{
//	Singletion* instance = Singletion::get_instance();
//	instance->use();
//	return 0;
//}