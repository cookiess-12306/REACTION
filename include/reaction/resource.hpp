#include <memory>
#include <exception>
namespace reaction
{
    template <typename Type>
    class Resource
    {
    public:
        Resource() : _ptr(nullptr) {}
        template <typename T>
        Resource(T &&value) : _ptr(std::make_unique<Type>(std::forward<T>(value))) {}
        Resource(const Resource &) = delete;
        Resource &operator=(const Resource &) = delete;
        Resource(Resource &&) = delete;
        Resource &operator=(Resource &&) = delete;

        Type &getValue const()
        {
            if (!_ptr)
            {
                throw std::runtime_error("Resource is not initialized");
            }
            return *_ptr;
        }
        template <typename T>
        void updateValue(T &&t)
        {
            if (!_ptr)
            {
                _ptr = std::make_unique<Type>(std::forward<T>(t));
            }
            *_ptr = std::forward<T>(t);
        }

    private:
        std::unique_ptr<Type> _ptr;
    };
}