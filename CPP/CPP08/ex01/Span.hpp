#ifndef ITER_HPP
#define ITER_HPP

 #include <vector>
 #include <iterator>

 class Span
 {
    private:
        unsigned int        _capacity;
        unsigned int        _size;
        std::vector<int>    _numbers;

    public:
        Span(unsigned int N);
        Span(Span const & other);
        Span & operator=(Span const & other);
        ~Span();

        void        addNumber(int number);
        long long   shortestSpan()  const;
        long long   longestSpan()   const;

        template <typename T>
        void insertRange(T begin, T end)
        {
            std::size_t count = static_cast<std::size_t>(std::distance(begin, end));

            if (_numbers.size() + count > _capacity)
                throw ( std::runtime_error("Span does not have enough space for range operation!") );

            _numbers.insert(_numbers.end(), begin, end);
            _size = _numbers.size();
        }
 };


 #define BOLD_CRIMSON "\033[1m\033[38;2;220;20;60m"
 #define RESET "\033[0m"


#endif
    