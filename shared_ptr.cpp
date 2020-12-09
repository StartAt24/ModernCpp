#include <iostream>
using namespace std;

enum class ShapeType{
    circle,
    triangle,
    rectangle
};

class Shape{

};

class Circle : public Shape{
};

class Triangle : public Shape{
};

class Rectangle : public Shape{
};


Shape* CreateShape(ShapeType type){
    switch(type){
        case ShapeType::circle:
            return new Circle();
        case ShapeType::triangle:
            return new Triangle();
        case ShapeType::rectangle:
            return new Rectangle();
    }
}

class ShapeWrapper{
public:
    ShapeWrapper(Shape* shape_ptr=nullptr):shape_ptr_(shape_ptr){
    }
    ~ShapeWrapper(){
        delete shape_ptr_;
    }
    Shape* get(){
        return shape_ptr_;
    }
private:
    Shape* shape_ptr_;
};

class SharedCount{
public:
    SharedCount():count_(1){

    };
    void AddCount(){
        ++count_;
    };
    long ReduceCount(){
        --count_;
    };
    long GetCount() const{
        return count_;
    };
private:
    long count_;
};


template<typename T>
class SmartPtr{
public:
    template<typename U>
    friend class SmartPtr;

    explict SmartPtr(T* ptr=nullptr):ptr_(ptr){
        if(ptr){
            shared_count_ = new SharedCount();
        }
    }
    template <typename U>
    SmartPtr(const SmartPtr<U>& other) noexcept{
        ptr_ = other.ptr_;
        if(ptr_){
            other.shared_count_->add_count();
            shared_count_ = other.shared_count_;
        }
    }
    // 移动构造
    template<typename U>
    SmartPtr(SmartPtr<U>&& other) noexcept{
        ptr_ = other.ptr_;
        if(ptr_){
            shared_count_ = other.shared_count_;
            other.ptr_ = nullptr;
        }
    }
    SmartPtr& operator=(SmartPtr rhs){
        rhs.swap(*this)
        return *this;
    }
    ~SmartPtr(){
        if(ptr_&& shared_count_->ReduceCount()){
            delete ptr_;
            delte shared_count_;
        }
    }

    long UseCount() const noexcept{
        if(ptr_){
            return shared_count_->GetCount();
        }else
            return 0;
    }
    
    template<typename U>
    SmartPtr(const SmartPtr<U>& other, T*ptr) noexcept{
        ptr_ = ptr;
        if(ptr_){
            other.shared_count_->AddCount();
            shared_count_ = other.shared_count_;
        }
    }


    void swap(SmartPtr& rhs) noexcept{
        using std::swap;
        swap(ptr_, rhs.ptr_);
        swap(shared_count_, rhs.shared_count_);
    }

    T* get() const{
        return ptr_;
    }

    T& operator*() const  noexcept{ return *ptr_; }
    T* operator->() const noexcept{ return ptr_; }
    operator bool() const noexcept{ return ptr_; }
private:
    T* ptr_;
    SharedCount *shared_count_;
};

template<typename T, typename U>
SmartPtr<T> DynamicPointerCast(const SmartPtr<U>& other){
    T* ptr = dynamic_cast<T*>(other.get());
    return SmartPtr<T>(other, ptr);
}

template<typename T, typename U>
SmartPtr<T> ReinterpretCast(const SmartPtr<U>& other){
    T* ptr = reinterpret_cast<T*>(other.get());
    return SmartPtr<T>(other, ptr);
}

template<typename T, typename U>
SmartPtr<T> ConstCast(const SmartPtr<U>& other){
    T* ptr = const_cast<T*>(other.get());
    return SmartPtr<T>(other, ptr);
}

template<typename T, typename U>
SmartPtr<T> StaticCast(const SmartPtr<U>& other){
    T* ptr = static_cast<T*>(other.get());
    return SmartPtr<T>(other, ptr);
}
int main(){
    return 0;
}



