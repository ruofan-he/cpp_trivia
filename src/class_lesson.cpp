#include <iostream>

using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;

class CSample
{
public:
    CSample(){
        m_num = 0;
        m_str = "hoge";
    }
    CSample(int num, char* str){
        m_num = num;
        m_str = str;
    }
    CSample(const CSample& sample){
        m_num = sample.m_num;
        m_str = sample.m_str;
    }
    ~CSample(){
        std::cout << "destructor" << std::endl;
        std::cout << m_num << std::endl;
        std::cout << m_str << std::endl;
    }
    CSample& operator=(const CSample& sample){
        m_num = sample.m_num;
        m_str = sample.m_str;
        return *this;
    }
    void function(){
        std::cout << "helloworld" << std::endl;
        std::cout << m_num << std::endl;
        std::cout << m_str << std::endl;
    }
private:
    int m_num;
    std::string m_str;
};


int main()
{
    std::cout << "helloworld" << std::endl;
    CSample sample = CSample();
    sample.function();
    CSample sample1 = CSample(0,"0");
    sample1.function();
    CSample sample2(1,"10");
    sample2.function();

    //非 const への参照の初期値は左辺値である必要がありますC/C++(461)
    // CSample& fail = CSample(); //error
    // CSample& fail(CSample());
    // fail.function();

    CSample& sample3 = *new CSample(2,"20");
    sample3.function();
    delete &sample3;

    // temporary object cannot be bound to a reference of type 'CSample *'
    // CSample* fail = &CSample();

    std::cout << "somesome" << std::endl;

    //error: taking the address of a temporary object of type 'CSample'
    //unique_ptr<CSample> b(&CSample(4,"40"));
    unique_ptr<CSample> a(new CSample(3,"30"));
    a->function();

    // unique_ptr try to delete sample2 but this is temporary object(not in heap object)
    unique_ptr<CSample> c(&sample2);
    c->function();

    return 0;
}