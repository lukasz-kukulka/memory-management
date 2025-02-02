template<typename T>
class UniquePtr {
public:
    UniquePtr() = default;

    explicit UniquePtr(T* ptr) {
        ptr_ = ptr;
    }

    UniquePtr(const UniquePtr& copy) = delete;

    UniquePtr(UniquePtr&& move) {
        ptr_ = move.ptr_;
        move.ptr_ = nullptr;
    }

    ~UniquePtr() {
        if (ptr_) {
            delete ptr_;
        }
    }
    
    UniquePtr& operator=(const UniquePtr& copy) = delete;
    UniquePtr& operator=(UniquePtr&& move) {
        if (&move != this) {
            delete ptr_;
            ptr_ = move.ptr_;
            move.ptr_ = nullptr;
        }
        return *this;
    }

    T& operator*() const {
        if (!ptr_) {
            throw std::runtime_error("wrong operation poiter = nullptr");
        }
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

    T* get() const {
        return ptr_;
    }

    T* release() {
        T* temp { ptr_ };
        ptr_ = nullptr;
        return temp;
    }

    void reset(T* data = nullptr) {
        if (data != ptr_) {
            delete ptr_;
            ptr_ = data;
        }
    }

private:
    T* ptr_ { nullptr };
};