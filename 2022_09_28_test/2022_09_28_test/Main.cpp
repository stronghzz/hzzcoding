#include <iostream>
#include <memory>
#include <mutex>

#include <iostream>
using namespace std;
class Singleton
{
private: //�����ڿ��ţ������ⲻ����
    static Singleton* singleton; //����ָ��
    Singleton()
    {
        cout << "Singleton�Ĺ���" << endl;
    }
public:
    //����һ�����нӿڣ����ر�������ָ��
    static Singleton* getInstance()
    {
        return singleton;
    }
    void showInfo()
    {
        cout << this << endl;
    }
    //�ѱ������Զ��ṩ�Ŀ��������� = ������������Ƴ�
    Singleton(const Singleton& other) = delete;
    void operator = (const Singleton& other) = delete;
};

Singleton* Singleton::singleton = new Singleton;
int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();
    Singleton* s3 = Singleton::getInstance();

    cout << s1 << "," << s2 << "," << s3 << endl; //s1��s2��s3 ��ַһ��
    return 0;
}
//class Chairman
//{
//public:
//	void print()
//	{
//		std::cout << "�������" << std::endl;
//	}
//private:
//	Chairman()
//	{
//		std::cout << "������" << std::endl;
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

//����ģʽ��ȫ��ֻ��һ��ʵ����ͬʱ��ֹ�û�����������ʵ�������캯����˽�е�
//��ֹ��ֵ�Ϳ���
//�̰߳�ȫ
//�û�ͨ���ӿڻ�ȡʵ����ʹ��static���Ա����

//����ģʽ:ֱ��ʹ��ʱ��ʵ��������Ҳ����˵ֱ������get_instance()������ʱ���newһ�������Ķ���
// 
//class Singleton {
//private:
//    Singleton() 
//    {
//        std::cout << "constructor called!" << std::endl;
//    }
//    Singleton(Singleton&) = delete;        //��ֹ��ֵ����
//    Singleton& operator=(const Singleton&) = delete;       //��ֹ��������
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
//	Singletion(Singletion&) = delete;//��ֹ��ֵ����
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