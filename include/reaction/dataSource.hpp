#include "reaction/expression.hpp"
namespace reaction
{
    template <typename T, typename... Args>
    class DataSource : public Expression<T, Args...>
    {
    public:
        auto get() const
        {
                }
    };

    template <typename T>
    auto var(T &&value)
    {
        return DataSource(std::forward<T>(value));
    }

    template <typename Fun, typename... Args>
    auto calc(Fun &&fun, Args &&...args)
    {
        return DataSource<Fun, Args...>(std::forward<Fun>(fun), std::forward<Args>(args)...);
    }
}