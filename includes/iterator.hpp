#pragma once
#include "ft_containers.hpp"

namespace ft
{
	template<class it>
	class reverse_iterator{
		public:
			it	_it;
		private:
			reverse_iterator	(void)												{ _it = it(); }
			reverse_iterator	(typename it::value_type * ptr)						{ _it = it(ptr); }
			reverse_iterator	(const it & x)										{ _it = x; --_it; }
			~reverse_iterator	(void)												{}

			reverse_iterator	&operator=(const reverse_iterator & x)						{_it = x.getIt(); return (*this); }
			reverse_iterator	&operator+=(int n)											{_it -= n; return (*this); }
			reverse_iterator	&operator-=(int n)											{_it += n; return (*this); }

			reverse_iterator 	&operator++(void)											{ --_it; return (*this); }
			reverse_iterator 	operator--(void)											{ ++_it; return (*this); }
			reverse_iterator	operator++(int)												{ reverse_iterator<it> x(*this); --_it; return (x); }
			reverse_iterator	operator--(int)												{ reverse_iterator<it> x(*this); ++_it; return (x); }

			std::ptrdiff_t		operator-	(const reverse_iterator & x) const				{ return (x.getIt() - _it); }

			template <class U> bool	operator==(const reverse_iterator<U> & x) const			{ return (_it == x.getIt()); }
			template <class U> bool	operator!=(const reverse_iterator<U> & x) const			{ return (_it != x.getIt()); }
			template <class U> bool	operator<(const reverse_iterator<U> & x) const			{ return (_it > x.getIt()); }
			template <class U> bool	operator>(const reverse_iterator<U> & x) const			{ return (_it < x.getIt()); }
			template <class U> bool	operator<=(const reverse_iterator<U> & x) const			{ return (_it >= x.getIt()); }
			template <class U> bool	operator>=(const reverse_iterator<U> & x) const			{ return (_it <= x.getIt()); }
			friend reverse_iterator	operator+	(int n, const reverse_iterator & x)		{ return (x.getIt() - n + 1); }

			reverse_iterator	operator+(int n) const										{ return (_it - n + 1); }
			reverse_iterator	operator-(int n) const										{ return (_it + n + 1); }

			typename it::value_type &	operator[](size_t n) const						{ return (*(_it - n)); }
			typename it::value_type &	operator*(void) const							{ return (*_it); }
			typename it::value_type *	operator->(void) const							{ return (&(*_it)); }

			it	base(void)						{ return (++it(_it)); }
	};

	template<class T>
	class RandomAccessIterator{
		protected:
			T* _ptr;
		public:
			RandomAccessIterator(void)	{ _ptr = nullptr; }
			RandomAccessIterator(T* ptr)	{ _ptr = ptr; }
			RandomAccessIterator(const RandomAccessIterator &othr)	{ *this = othr; }
			~RandomAccessIterator(void)	{}

			RandomAccessIterator& operator=(const RandomAccessIterator &othr)
			{
				_ptr = othr._ptr;
				return (*this);
			}
			bool operator==(const RandomAccessIterator &othr) const
			{
				return (_ptr == othr._ptr);
			}
			bool operator!=(const RandomAccessIterator &othr) const
			{
				return (_ptr != othr._ptr);
			}
			T &operator*(void) const
			{
				return (*_ptr);
			}
			T *operator->(void) const
			{
				return (_ptr);
			}
			RandomAccessIterator& operator++(void)
			{
				++_ptr;
				return (*this);
			}
			RandomAccessIterator& operator--(void)
			{
				--_ptr;
				return (*this);
			}
			RandomAccessIterator operator++(int)
			{
				RandomAccessIterator tmp(*this);
				operator++();
				return (tmp);
			}
			RandomAccessIterator operator--(int)
			{
				RandomAccessIterator tmp(*this);
				operator--();
				return (tmp);
			}
			RandomAccessIterator operator+(int n)
			{
				RandomAccessIterator tmp(*this);
				tmp._ptr += n;
				return (tmp);
			}
			RandomAccessIterator operator-(int n)
			{
				RandomAccessIterator tmp(*this);
				tmp._ptr -= n;
				return (tmp);
			}
			bool operator<(const RandomAccessIterator &othr) const
			{
				return (_ptr < othr._ptr);
			}
			bool operator>(const RandomAccessIterator &othr) const
			{
				return (_ptr > othr._ptr);
			}
			bool operator<=(const RandomAccessIterator &othr) const
			{
				return (_ptr <= othr._ptr);
			}
			bool operator>=(const RandomAccessIterator &othr) const
			{
				return (_ptr >= othr._ptr);
			}
			RandomAccessIterator &operator+=(int n)
			{
				_ptr += n;
				return (*this);
			}
			RandomAccessIterator &operator-=(int n)
			{
				_ptr -= n;
				return (*this);
			}
			T &operator[](int n)
			{
				return (_ptr[n]);
			}
			
	};
	
}