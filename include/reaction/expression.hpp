#include <tuple>
#include "reaction/resource.hpp"

namespace reaction
{
    template <typename Fun, typename... Args>
    class Expression : public Resource<>
    {
    public:
        template <typename F, typename... A>
        Expression(F &&f, A &&...a) : Resource<>(),
                                      _fun(std::forward<F>(f)),
                                      _args(std::forward<A>(a)...)
        {
        }

    private:
        Fun _fun;
        std::tuple<Args...> _args;
    };

    template <typename Type>
    class Expression<Type> : Resource<Type>
    {
    public:
        // Expression(Type &&t) : Resource<Type>(std::forward<Type>(t)) {}
        using Resource<Type>::Resource;
    };
}