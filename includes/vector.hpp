#pragma once
#include "ft_containers.hpp"
# ifndef SIZE_OR_CAP_
#  if __APPLE__
#   define SIZE_OR_CAP_ _container_size
#  else
#   define SIZE_OR_CAP_ _container_length
#  endif
# endif

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector{
		public:
		typedef		T												value_type;
		typedef		Alloc											allocator_type;
		typedef		typename allocator_type::reference				reference;
		typedef		typename allocator_type::const_reference		const_reference;
		typedef		typename allocator_type::pointer				pointer;
		typedef		typename allocator_type::const_pointer			const_pointer;
		typedef		ft::RandomAccessIterator<T>						iterator;
		typedef		ft::RandomAccessIterator<T>						const_iterator;
		typedef		ft::reverse_iterator<iterator>					reverse_iterator;
		typedef		ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef		std::size_t										size_type;
		typedef 	long int                                    	difference_type;
		
		private:
			pointer 			_container;
			size_t				_container_size; //to size_type partout
			size_t				_container_length; //to size_type partout
			allocator_type		_alloc;
			//value_type*			_container;
		//typedef		typename RandomAccessIterator::difference_type	difference_type;
		
		public :
		explicit vector(const allocator_type &allocator = allocator_type()) : _container(0), _container_size(0), _container_length(0) , _alloc(allocator)
		{
			_container = _alloc.allocate(0);
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &allocator = allocator_type()) : _container(0), _container_size(0), _container_length(0) ,_alloc(allocator)
		{
			_container = _alloc.allocate(0);
			assign(first, last);
		}
		explicit vector(size_type n, const_reference val = value_type(), const allocator_type &allocator = allocator_type()) : _container(0) , _container_size(0), _container_length(0) , _alloc(allocator)
		{
			_container = _alloc.allocate(0);
			assign(n, val);
		}
		vector(const vector &othr): _container(0), _container_size(0), _container_length(0), _alloc(othr._allocator)  	{ *this = othr; }
		~vector (void) { _alloc.deallocate(_container, _container_size);}

		// Iterator
		iterator begin (void)				{ return (iterator(_container)); }
		iterator end (void)					{ return (iterator(_container + _container_length)); }
		const_iterator begin(void) const	{ return (const_iterator(_container));}
		const_iterator end (void) const		{ return (const_iterator(_container + _container_length));}
		const_reverse_iterator rbegin (void) const { return (const_reverse_iterator(_container + _container_length - 1)); }
		const_reverse_iterator rend (void) const { return (const_reverse_iterator(_container - 1)); }
		reverse_iterator rbegin (void) { return (reverse_iterator(_container +_container_length - 1)); }
		reverse_iterator rend (void) { return (reverse_iterator(_container - 1)); }

		// Capacity
		size_t	size (void) const { return (_container_size); }
		size_t	max_size (void) const { return (_alloc.max_size()); }
		void	resize (size_t n, value_type val = value_type()) // To verif
		{
			if (n > _container_size)
			{
				insert(end(), n - _container_size, val);
			}
			else if (n < _container_size)
			{
				erase(begin() + n, end());
			}
		}
		size_t capacity (void) const{return (_container_size);}
		bool empty (void) const{ return (_container_size == 0);}
		void reserve(size_t n)
		{
			// if (n > _alloc.max_size())
			// 	throw std::length_error("ft::vector::reserve : n > max_size");
			if (n > _container_size)
			{
				size_t i = -1;
				pointer	tmp;
				tmp  = _alloc.allocate(n);
				while (++i < _container_length)
					tmp[i] = _container[i];
				_alloc.deallocate(_container, _container_size );
				_container_size = n;
				_container = tmp;
			}
		};
		// Member access
		reference operator[] (size_t n) { return (_container[n]); }
		reference at (size_t n)
		{
			if (n >= _container_size)
				throw std::out_of_range("vector");
			return (_container[n]);
		}
		reference front (void)
		{
			return (_container[0]);
		}
		
		reference back (void)
		{
			return (_container[_container_size - 1]);
		}

		// Modifiers
		void push_back (const value_type& val)
		{
			if (_container_length + 1 > _container_size)
				reserve(_container_length + 1);
			_container[_container_length++] = val;
		};
		void pop_back()
		{
			if (_container_length > 0)
				_container_length--;
		};
		iterator erase(iterator pos)
		{
			iterator index = pos;
			while (index + 1 != end())
			{
				*index = *(index + 1);
				index++;
			}
			_container_length--;
			return (iterator(pos));
		};
		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				erase(first);
				last--;
			}
			return (iterator(first));
		};
		// iterator insert(iterator position, const value_type &value)
		// {
		// 	size_type i = 0;
		// 	iterator it = begin();
		// 	while (it + i != position && i < _container_length)
		// 		i++;
		// 	// std::cout << "i = " << i << std::endl;
		// 	// -std::cout << "_container_size = " << _container_size << std::endl;
		// 	if (_container_size < _container_length + 1)
		// 		reserve(_container_length + 1);
		// 	size_type j = _container_size - 1;
		// 	// std::cout << "j = " << j << std::endl;
		// 	// std::cout << "_container_size = " << _container_size << std::endl;
		// 	// std::cout << "_container_length = " << _container_length << std::endl;
		// 	while (j > i)
		// 	{
		// 		//std::cout << _container[0] << std::endl;
		// 		_container[j] = _container[j - 1];
		// 		//std::cout << _container[j] << std::endl;
		// 		j--;
		// 	}
		// 	_container[i] = value;
		// 	_container_length++;
		// 	return (iterator(&_container[i]));
		// };
		// void insert(iterator position, size_type n, const value_type &value)
		// {
		// 	while (n--)
		// 	{
		// 		// std::cout << "insert " << n << std::endl;
		// 		position = insert(position, value);
		// 	}
		// };
		// template <class InputIterator>
		// void insert(iterator position, InputIterator begin, InputIterator end)
		// {
		// 	while (begin != end)
		// 	{
		// 		//std::cout << "insert : " << begin[0] << std::endl;
		// 		//std::cout << "insert : " << begin << std::endl;
		// 		position = insert(position, begin) + 1;
		// 		++begin;
		// 	}
		// };
		iterator insert (iterator position, const value_type& val)
        {
            difference_type index = position - begin();
            
            insert(position, 1, val);
            return iterator(&_container[index]);
        }
        void insert (iterator position, size_type n, const value_type& val)
        {
            difference_type index = position - begin();
            
            if (_container_length + n > _container_size)
                reserve(_container_length + n);
            
            iterator newPosition(&_container[index]);
            
			size_type tn = n;
			difference_type temp = index;
			while (tn)
			{
				_container[temp + n] = _container[temp];
				temp++;
				tn--;
			}
            
            // Constructing n new elements from val
            for (size_type i = 0; i < n; ++i)
			{
				_container[index + i] = val;
				std::cout << "insert : " << val << std::endl;
			}
            _container_length += n;
		}
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, 
        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
        {
            size_type n = 0;
            InputIterator tmp(first);
            while (tmp++ != last)
                ++n;
            
            difference_type index = position - begin();
            
            if (_container_length + n > _container_size)
                reserve(_container_length + n);

            iterator newPosition(&_container[index]);
            
			size_type tn = n;
			difference_type temp = index;
            // if (newPosition != end())
            //     moveElementsToTheRight(newPosition, n);
			while (tn)
			{
				//_container[temp + n] = _container[temp];
				//std::cout << "temp = " << *temp << std::endl;
				
				temp++;
				tn--;
			}
            for (size_type i = 0; i < n; ++i)
                _alloc.construct(&(*newPosition++), *first++);
            _container_length += n;
        }
		void swap (vector &othr)
		{
			ft::swap(_container, othr._container);
			ft::swap(_container_size, othr._container_size);
			ft::swap(_container_length, othr._container_length);
		};
		void clear(void)
		{
			erase(begin(), end());
		};
		// template <class InputIterator>
		// void assign(InputIterator first, InputIterator last)
		// {
		// 	clear();
		// 	insert(begin(), first, last);
		// };
		// void assign(size_type n, const value_type &value)
		// {
		// 	clear();
		// 	insert(begin(), n, value);
		// };
		template <class InputIterator>
        void assign (InputIterator first, InputIterator last,
        typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
        {
            clear();
            size_type n = static_cast<size_type>(last - first);
            // if (n > _container_size)
            // {
                _alloc.deallocate(_container, _container_size);
                _container = _alloc.allocate(n);
				_container_size = n;
            // }
            
            size_type i = 0;
            for (; first != last; ++i, ++first)
               _container[i] = *first;
            _container_length = i;
        }  
        void assign (size_type n, const value_type& val)
        {
            clear();
            // if (n > _container_size)
            // {
                _alloc.deallocate(_container, _container_size);
                _container = _alloc.allocate(n);
				_container_size = n;
			// }
            
            for (size_type i = 0; i < n; ++i)
                _container[i] = val;
            _container_length = n;
        }
		template <class InputIterator>
		allocator_type get_allocator (void) const { return (allocator_type()); }
	};
};