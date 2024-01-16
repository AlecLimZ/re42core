/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 14:24:13 by leng-chu          #+#    #+#             */
/*   Updated: 2023/01/19 17:39:21 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "util.hpp"
# include "RBT.hpp"

namespace	ft
{
	template <typename P, typename Cmp>
	struct ftcmp : std::binary_function<P, P, bool>
	{
		Cmp compare;
		bool operator()(P a, P b) const
		{
			return (compare(a.first,b.first));
		}
	};

	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> >
			>
	class map
	{
		template <typename V>
		class mapiter;
		template <typename V>
		class mapitrev;
		public:
			typedef Key	key_type;
			typedef T	mapped_type;
			typedef ft::pair<const Key, T>	value_type;
			typedef std::size_t	size_type;
			typedef std::ptrdiff_t	difference_type;
			typedef Compare	key_compare;
			typedef Allocator	allocator_type;
			typedef value_type&	reference;
			typedef const value_type&	const_reference;
			typedef typename Allocator::pointer	pointer;
			typedef typename Allocator::const_pointer	const_pointer;
			typedef mapiter<value_type>	iterator;
			typedef mapiter<const value_type> const_iterator;
			typedef mapitrev<iterator>	reverse_iterator;
			typedef mapitrev<const iterator> const_reverse_iterator;
			typedef RedBlackTree<Key, mapped_type, value_type, allocator_type, key_compare> RBTclass;
			typedef typename RedBlackTree<Key, mapped_type, value_type, allocator_type, key_compare>::NodePtr NodePtr;
			typedef typename RedBlackTree<Key, mapped_type, value_type, allocator_type, key_compare>::NodeM NodeM;
			typedef ftcmp<value_type, key_compare>	value_compare;

		protected:
			size_type		_size;
			allocator_type	_myalloc;
			RBTclass		_rbtmap;
			key_compare		_compare;

		public:
			/***CONSTRUCTOR & DESTRUCTOR***/
			explicit map(const Compare & comp = key_compare(), const allocator_type & alloc = Allocator())
				:_size(0), _myalloc(alloc), _compare(comp){}
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::value_type* = 0)
			: _size(0), _myalloc(alloc), _compare(comp)
			{
				if (_size > max_size())
					throw(std::length_error("ft::map"));
				NodePtr	check;
				value_type tmp;
				while (first != last)
				{
					check = _rbtmap.insert(first->first);
					if (check->data.second == tmp.second)
						check->data.second = first->second;
					first++;
				}
				_size = _rbtmap.getSize();
			}
			map(const map & x): _size(x._size), _myalloc(x._myalloc), _rbtmap(), _compare(x._compare)
			{
				const_iterator it = x.begin();
				const_iterator ite = x.end();
				insert(it, ite);
				_size = _rbtmap.getSize();
			}
			map & operator=(const map & rhs)
			{
				if (this != &rhs)
				{
					_size = rhs._size;
					_myalloc = rhs._myalloc;
					_rbtmap = rhs._rbtmap;
					_compare = rhs._compare;
					insert(rhs.begin(), rhs.end());
				}
				return (*this);
			}
			~map()
			{}

			//test
			void	print(void)
			{
				_rbtmap.inorder();
			}
			/*** ITERATOR ***/
			iterator begin()
			{
				return (iterator(&_rbtmap));
			}
			
			const_iterator begin() const
			{
				return (const_iterator(&_rbtmap));
			}

			iterator end()
			{ return (iterator(&_rbtmap, _rbtmap.getNull())); }

			const_iterator end() const
			{ return (const_iterator(&_rbtmap, _rbtmap.getNull())); }

			reverse_iterator rbegin()
			{
				return (reverse_iterator(--end()));
			}

			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(--end()));
			}

			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			/*** ELEMENT ACCESS ***/
			mapped_type & operator[](const key_type & k)
			{
				NodePtr	check = _rbtmap.insert(k);
				return (check->data.second);
			}

			mapped_type & at(const key_type & k)
			{
				NodePtr find = _rbtmap.searchTree(k);
				if (find == _rbtmap.getNull())
					throw(std::out_of_range("ft::map::at: key not found\n"));
				return (find->data.second);
			}

			const mapped_type & at(const key_type & k) const
			{
				NodePtr find = _rbtmap.searchTree(k);
				if (find == _rbtmap.getNull())
					throw(std::out_of_range("ft::map::at: key not found\n"));
				return (find->data.second);
			}

			/*** CAPACITY ***/
			bool empty() const
			{
				return (_size == 0);
			}

			size_type size() const
			{
				return (_rbtmap.getSize());
			}

			size_type max_size() const
			{
				std::allocator<char> tmp;
				if (sizeof(value_type) == 2)
					return (tmp.max_size() / 32);
				if (sizeof(value_type) == 12)
					return (tmp.max_size() / (28 + sizeof(value_type)));
				return (tmp.max_size() / (32 + sizeof(value_type)));
			}
			/*** MODIFIERS ***/
			ft::pair<iterator, bool> insert(const value_type & val)
			{
				ft::pair<iterator, bool> ret;
				ft::pair<NodePtr, bool> box;

				box = _rbtmap.insert2(val.first);
				if (box.second)
					box.first->data.second = val.second;
				ret = ft::make_pair(iterator(&_rbtmap, box.first), box.second);
				_size = _rbtmap.getSize();
				return (ret);
			}
			iterator insert(iterator position, const value_type & val)
			{
				NodePtr pos = position._map;
				position._map = _rbtmap.insert3(pos, val.first, val.second);
				_size = _rbtmap.getSize();
				return (position);
			}
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::value_type* = 0)
			{
				if (_size > max_size())
					throw(std::length_error("ft::map::insert"));
				NodePtr	check;
				value_type tmp;
				while (first != last)
				{
					check = _rbtmap.insert(first->first);
					if (check->data.second == tmp.second)
						check->data.second = first->second;
					first++;
				}
				_size = _rbtmap.getSize();
			}

			void		erase(iterator position)
			{
				_rbtmap.remove(position._map);
				_size = _rbtmap.getSize();
			}
			size_type	erase(const key_type & k)
			{
				NodePtr d = _rbtmap.searchTree(k);
				if (d == _rbtmap.getNull())
					return (0);
				_rbtmap.remove(d);
				_size = _rbtmap.getSize();
				return (1);
			}
			void		erase(iterator first, iterator last)
			{
				while (first != last)
					_rbtmap.remove((first++)._map);
				_size = _rbtmap.getSize();
			}
			void swap(map & x)
			{
				size_type 		s = _size;
				allocator_type	a = _myalloc;
				key_compare		c = _compare;
				_size = x._size;
				_myalloc = x._myalloc;
				_compare = x._compare;
				x._size = s;
				x._myalloc = a;
				x._compare = c;
				_rbtmap.swap(x._rbtmap);
			}

			void clear()
			{
				_rbtmap.clear();
				_size = _rbtmap.getSize();
			}
			/*** OBSERVERS ***/
			key_compare	key_comp() const
			{
				return (_compare);
			}

			value_compare value_comp() const
			{
				value_compare lol;
				return (lol);
			}
			/*** OPERATIONS ***/
			iterator find(const key_type & k)
			{
				NodePtr find = _rbtmap.searchTree(k);
				iterator ret(&_rbtmap, find);
				return (ret);
			}
			const_iterator find(const key_type & k) const
			{
				NodePtr find = _rbtmap.searchTree(k);
				const_iterator ret(&_rbtmap, find);
				return (ret);
			}

			size_type count (const key_type & k) const
			{
				NodePtr find = _rbtmap.searchTree(k);
				if (find == _rbtmap.getNull())
					return (0);
				return (1);
			}

			iterator lower_bound(const key_type & k)
			{
				iterator it = begin();
				iterator ite = end();
				reverse_iterator rit = rbegin();
				if (_compare(k, it->first))
					return (it);
				if (_compare(rit->first, k))
					return (ite);
				while (it != ite)
				{
					if (k == it->first)
						return (it);
					if (_compare(k, it->first))
						return (it);
					it++;
				}
				return (it);
			}
			const_iterator lower_bound(const key_type & k) const
			{
				const_iterator it = begin();
				const_iterator ite = end();
				const_reverse_iterator rit = rbegin();
				if (_compare(k, it->first))
					return (it);
				if (_compare(rit->first, k))
					return (ite);
				while (it != ite)
				{
					if (k == it->first)
						return (it);
					if (_compare(k, it->first))
						return (it);
					it++;
				}
				return (it);
			}
			iterator upper_bound(const key_type & k)
			{
				iterator it = begin();
				iterator ite = end();
				reverse_iterator rit = rbegin();
				if (_compare(k, it->first))
					return (it);
				if (_compare(rit->first, k))
					return (ite);
				while (it != ite)
				{
					if (_compare(k, it->first))
						return (it);
					it++;
				}
				return (it);
			}
			const_iterator upper_bound(const key_type & k) const
			{
				const_iterator it = begin();
				const_iterator ite = end();
				const_reverse_iterator rit = rbegin();
				if (_compare(k, it->first))
					return (it);
				if (_compare(rit->first, k))
					return (ite);
				while (it != ite)
				{
					if (_compare(k, it->first))
						return (it);
					it++;
				}
				return (it);
			}

			pair<const_iterator, const_iterator> equal_range(const key_type & k) const
			{
				ft::pair<const_iterator, const_iterator> ret;
				ret = ft::make_pair(lower_bound(k), upper_bound(k));
				return (ret);
			}
			pair<iterator, iterator> equal_range(const key_type & k)
			{
				ft::pair<iterator, iterator> ret;
				ret = ft::make_pair(lower_bound(k), upper_bound(k));
				return (ret);
			}
			/*** ALLOCATOR ***/
			allocator_type get_allocator() const
			{
				return (allocator_type(_myalloc));
			}

			/*** Non-member functions ***/
			template<class KK, class TT, class CC, class AA>
			friend bool operator==(const ft::map<KK, TT, CC, AA> & lhs, const ft::map<KK, TT, CC, AA> & rhs)
			{
				typedef typename ft::map<KK, TT, CC, AA>::const_iterator ftiter;
				if (lhs.size() != rhs.size())
					return (false);
				ftiter L1 = lhs.begin(), L2 = lhs.end();
				ftiter R1 = rhs.begin(), R2 = rhs.end();
				while (L1 != L2 && R1 != R2)
				{
					if (L1->first != R1->first || L1->second != R1->second)
						return (false);
					L1++;
					R1++;
				}
				if (L1->first != R1->first || L1->second != R1->second)
					return (false);
				return (true);
			}
			
			template<class KK, class TT, class CC, class AA>
			friend bool operator!=(const ft::map<KK, TT, CC, AA> & lhs, const ft::map<KK, TT, CC, AA> & rhs)
			{
				return (!(lhs == rhs));
			}

			template<class KK, class TT, class CC, class AA>
			friend bool operator<(const ft::map<KK, TT, CC, AA> & lhs, const ft::map<KK, TT, CC, AA> & rhs)
			{
				return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
			}

			template<class KK, class TT, class CC, class AA>
			friend bool operator<=(const ft::map<KK, TT, CC, AA> & lhs, const ft::map<KK, TT, CC, AA> & rhs)
			{
				return (!(rhs < lhs));
			}

			template<class KK, class TT, class CC, class AA>
			friend bool operator>(const ft::map<KK, TT, CC, AA> & lhs, const ft::map<KK, TT, CC, AA> & rhs)
			{
				return (rhs < lhs);
			}

			template<class KK, class TT, class CC, class AA>
			friend bool operator>=(const ft::map<KK, TT, CC, AA> & lhs, const ft::map<KK, TT, CC, AA> & rhs)
			{
				return (!(lhs < rhs));
			}

			template<class KK, class TT, class CC, class AA>
			friend void swap(ft::map<KK, TT, CC, AA> & lhs, ft::map<KK, TT, CC, AA> & rhs);
	};

	template<class KK, class TT, class CC, class AA>
	void swap(ft::map<KK, TT, CC, AA> & lhs, ft::map<KK, TT, CC, AA> & rhs)
	{
		lhs.swap(rhs);
	}


	// iterator for map
	template<typename K, typename T, typename C, typename A>
	template <typename V>
	class map<K, T, C, A>::mapiter
	{
		public:
			typedef map<K, T, C, A>			MAP;
			typedef MAP::difference_type	difference_type;
			typedef V						value_type;
			typedef V&						reference;
			typedef V*						pointer;
			typedef std::bidirectional_iterator_tag	iterator_category;

		protected:
			RBTclass	*_rc;
			NodePtr		_map;
			key_compare	_compare;
			friend class	mapiter<const V>;
			friend class	mapitrev<iterator>;
			friend class	mapitrev<const iterator>;
			friend class	map<K, T, C, A>;

		public:
			mapiter(void): _map(nullptr)
			{}
			~mapiter(void){}
			mapiter(RBTclass *rc): _rc(rc)
			{
				if (_rc->getSize() == 0)
					_map = _rc->getNull();
				else
					_map = _rc->minimum(_rc->getRoot());
			}
			mapiter(RBTclass *rc, NodePtr n): _rc(rc), _map(n)
			{}
			mapiter(const mapiter<typename std::remove_const<V>::type> & src)
			: _rc(src._rc), _map(src._map), _compare(src._compare){}
			mapiter & operator=(mapiter const & rhs)
			{
				if (this != &rhs)
				{
					_rc = rhs._rc;
					_map = rhs._map;
					_compare = rhs._compare;
				}
				return (*this);
			}

			template<typename X, typename Y>
			friend bool operator==(const mapiter<X> & lhs, const mapiter<Y> & rhs)
			{
				return (lhs._map == rhs._map);
			}
			
			template<typename X, typename Y>
			friend bool operator!=(const mapiter<X> & lhs, const mapiter<Y> & rhs)
			{ return (!(lhs == rhs)); }

			mapiter & operator++()
			{
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (((_map->left == nullNode && _map->right == nullNode)
						&& _map->parent == nullptr) || _map->parent == nullNode)
						_map = nullNode;
				else if (_map->parent && _compare(_map->data.first, _map->parent->data.first)
						&& _map->right == nullNode)
						_map = _map->parent;
				else if (_map->right != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else if (_map->right == nullptr)
						_map = _rc->minimum(_rc->getRoot());
					else
						_map = _rc->minimum(_map->right);
				}
				else
				{
						NodePtr p = _map->parent;
						while (p != nullptr && _compare(p->data.first, _map->data.first))
							p = p->parent;
						if (p == nullptr)
							_map = nullNode;
						else
							_map = p;
				}
				return (*this);
			}

			mapiter operator++(int)
			{
				mapiter old(*this);
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (((_map->left == nullNode && _map->right == nullNode)
						&& _map->parent == nullptr) || _map == nullNode)
						_map = nullNode;
				else if (_map->parent && _compare(_map->data.first, _map->parent->data.first)
						&& _map->right == nullNode)
						_map = _map->parent;
				else if (_map->right != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else if (_map->right == nullptr)
						_map = _rc->minimum(_rc->getRoot());
					else
						_map = _rc->minimum(_map->right);
				}
				else
				{
						NodePtr p = _map->parent;
						while (p != nullptr && _compare(p->data.first, _map->data.first))
							p = p->parent;
						if (p == nullptr)
							_map = nullNode;
						else
							_map = p;
				}
				return (old);
			}

			mapiter & operator--()
			{
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (_map == nullNode && _rc->getSize() >= 1)
					_map = _rc->maximum(_rc->getRoot());
				else if (_map->left != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->maximum(_map->left);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(_map->data.first, p->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullptr;
					else
						_map = p;
				}
				return (*this);
			}

			mapiter operator--(int)
			{
				mapiter old(*this);
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (_map == nullNode && _rc->getSize() >= 1)
					_map = _rc->maximum(_rc->getRoot());
				else if (_map->left != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->maximum(_map->left);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(_map->data.first, p->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullptr;
					else
						_map = p;
				}
				return (old);
			}

			reference operator*() const
			{ return (_map->data); }

			pointer operator->() const
			{
				return (&_map->data);
			}
	};
	
	template<typename K, typename T, typename C, typename A>
	template <typename V>
	class map<K, T, C, A>::mapiter<const V>
	{
		public:
			typedef map<K, T, C, A>			MAP;
			typedef MAP::difference_type	difference_type;
			typedef V						value_type;
			typedef const V&				const_reference;
			typedef const V*				const_pointer;
			typedef V&						reference;
			typedef V*						pointer;
			typedef std::bidirectional_iterator_tag	iterator_category;

		protected:
			const RBTclass	*_rc;
			NodePtr		_map;
			key_compare	_compare;
			template <typename Iter>
			friend class mapitrev;
			friend class mapiter<V>;

		public:
			mapiter(void): _map(nullptr)
			{}
			~mapiter(void){}
			mapiter(const RBTclass *rc): _rc(rc)
			{
				if (_rc->getSize() == 0)
					_map = _rc->getNull();
				else
					_map = _rc->minimum(_rc->getRoot());
			}
			mapiter(const RBTclass *rc, NodePtr n): _rc(rc), _map(n){}
			mapiter(const mapiter<typename std::remove_const<value_type>::type> & src)
			: _rc(src._rc), _map(src._map), _compare(src._compare){}
			mapiter & operator=(mapiter const & rhs)
			{
				if (this != &rhs)
				{
					_rc = rhs._rc;
					_map = rhs._map;
					_compare = rhs._compare;
				}
				return (*this);
			}

			template<typename X, typename Y>
			friend bool operator==(const mapiter<X> & lhs, const mapiter<Y> & rhs)
			{ return (lhs._map == rhs._map); }
			
			template<typename X, typename Y>
			friend bool operator!=(const mapiter<X> & lhs, const mapiter<Y> & rhs)
			{ return (!(lhs == rhs)); }

			mapiter & operator++()
			{
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (((_map->left == nullNode && _map->right == nullNode)
						&& _map->parent == nullptr) || _map->parent == nullNode)
					_map = nullNode;
				else if (_map->parent && _compare(_map->data.first, _map->parent->data.first) && _map->right == nullNode)
					_map = _map->parent;
				else if (_map->right != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->minimum(_map->right);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(p->data.first, _map->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullNode;
					else
						_map = p;
				}
				return (*this);
			}

			mapiter operator++(int)
			{
				mapiter old(*this);
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (((_map->left == nullNode && _map->right == nullNode)
						&& _map->parent == nullptr) || _map->parent == nullNode)
					_map = nullNode;
				else if (_map->parent && _compare(_map->data.first, _map->parent->data.first) && _map->right == nullNode)
					_map = _map->parent;
				else if (_map->right != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->minimum(_map->right);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(p->data.first, _map->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullNode;
					else
						_map = p;
				}
				return (old);
			}

			mapiter & operator--()
			{
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (_map == nullNode && _rc->getSize() >= 1)
					_map = _rc->maximum(_rc->getRoot());
				else if (_map->left != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->maximum(_map->left);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(_map->data.first, p->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullptr;
					else
						_map = p;
				}
				return (*this);
			}

			mapiter operator--(int)
			{
				mapiter old(*this);
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (_map == nullNode && _rc->getSize() >= 1)
					_map = _rc->maximum(_rc->getRoot());
				else if (_map->left != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->maximum(_map->left);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(_map->data.first, p->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullptr;
					else
						_map = p;
				}
				return (old);
			}

			const_reference operator*() const
			{ return (_map->data); }
			
			const_pointer operator->() const
			{ return (&_map->data); }
	};

	template<typename K, typename T, typename C, typename A>
	template<typename Iter>
	class map<K, T, C, A>::mapitrev
	{
		public:
			typedef map<K, T, C, A>				MAP;
			typedef Iter						iterator_type;
			typedef typename ft::iterator_traits<iterator>::value_type
				value_type;
			typedef typename ft::iterator_traits<iterator>::difference_type
				difference_type;
			typedef typename ft::iterator_traits<iterator>::pointer
				pointer;
			typedef typename ft::iterator_traits<iterator>::reference
				reference;
			typedef typename ft::iterator_traits<iterator>::iterator_category
				iterator_category;
		protected:
			RBTclass	*_rc;
			NodePtr		_map;
			key_compare	_compare;
			friend class mapitrev<const Iter>;
			friend class mapitrev<const_iterator>;

		public:
			mapitrev(void)
			: _rc(nullptr), _map(nullptr), _compare(){}
			~mapitrev(void){}
			mapitrev(reverse_iterator it)
			: _rc(it._rc), _map(it._map), _compare(it._compare)
			{}
			mapitrev(iterator it)
			: _rc(it._rc), _map(it._map), _compare(it._compare)
			{
				if (_rc->getSize() >= 1 && _map == _rc->minimum(_rc->getRoot()))
						_map = _rc->getNull();
			}
			mapitrev(const mapitrev & src)
			: _rc(src._rc), _map(src._map), _compare(src._compare){}
			mapitrev & operator=(mapitrev const & rhs)
			{
				if (this != &rhs)
				{
					_rc = rhs._rc;
					_map = rhs._map;
					_compare = rhs._compare;
				}
				return (*this);
			}

			iterator_type base() const
			{
				mapitrev tmp(*this);
				--tmp;
				return (iterator(_rc, tmp._map));
			}

			template<typename X, typename Y>
			friend bool operator==(const mapitrev<X> & lhs, const mapitrev<Y> & rhs)
			{
				return (lhs._map == rhs._map);
			}

			template<typename X, typename Y>
			friend bool operator!=(const mapitrev<X> & lhs, const mapitrev<Y> & rhs)
			{
				return (!(lhs == rhs));
			}

			mapitrev & operator++()
			{
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (_map == nullNode && _rc->getSize() >= 1)
					_map = _rc->maximum(_rc->getRoot());
				else if (_map->left != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->maximum(_map->left);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(_map->data.first, p->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullNode;
					else
						_map = p;
				}
				return (*this);
			}

			mapitrev operator++(int)
			{
				mapitrev old(*this);
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (_map == nullNode && _rc->getSize() >= 1)
					_map = _rc->maximum(_rc->getRoot());
				else if (_map->left != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->maximum(_map->left);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(_map->data.first, p->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullNode;
					else
						_map = p;
				}
				return (old);
			}

			mapitrev & operator--()
			{
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (_map == nullNode && _rc->getSize() >= 1)
					_map = _rc->minimum(_rc->getRoot());
				else if (((_map->left == nullNode && _map->right == nullNode)
						&& _map->parent == nullptr) || _map->parent == nullNode)
					_map = nullNode;
				else if (_map->parent && _compare(_map->data.first, _map->parent->data.first) && _map->right == nullNode)
					_map = _map->parent;
				else if (_map->right != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->minimum(_map->right);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(p->data.first, _map->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullptr;
					else
						_map = p;
				}
				return (*this);
			}

			mapitrev operator--(int)
			{
				mapitrev old(*this);
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (_map == nullNode && _rc->getSize() >= 1)
					_map = _rc->minimum(_rc->getRoot());
				else if (((_map->left == nullNode && _map->right == nullNode)
						&& _map->parent == nullptr) || _map->parent == nullNode)
					_map = nullNode;
				else if (_map->parent && _compare(_map->data.first, _map->parent->data.first) && _map->right == nullNode)
					_map = _map->parent;
				else if (_map->right != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->minimum(_map->right);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(p->data.first, _map->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullptr;
					else
						_map = p;
				}
				return (old);
			}

			reference operator*() const
			{
				return (_map->data);
			}

			pointer operator->() const
			{
				return (&_map->data);
			}
	};

	template<typename K, typename T, typename C, typename A>
	template <typename Iter>
	class map<K, T, C, A>::mapitrev<const Iter>
	{
		public:
			typedef map<K, T, C, A>		MAP;
			typedef Iter				iterator_type;
			typedef typename	ft::iterator_traits<iterator_type>::value_type
				value_type;
			typedef typename	ft::iterator_traits<iterator_type>::difference_type
				difference_type;
			typedef const value_type& const_reference;
			typedef const value_type* const_pointer;
			typedef typename	ft::iterator_traits<iterator>::iterator_category
				iterator_category;
		protected:
			const RBTclass	*_rc;
			NodePtr		_map;
			key_compare	_compare;
		public:
			mapitrev(void)
			: _rc(nullptr), _map(nullptr), _compare(){}
			~mapitrev(void){}
			mapitrev(reverse_iterator it)
			: _rc(it._rc), _map(it._map), _compare(it._compare)
			{}
			mapitrev(const_iterator it)
			: _rc(it._rc), _map(it._map), _compare(it._compare)
			{
				if (_rc->getSize() >= 1 && _map == _rc->minimum(_rc->getRoot()))
						_map = _rc->getNull();
			}
			mapitrev(iterator it)
			: _rc(it._rc), _map(it._map), _compare(it._compare)
			{
				if (_rc->getSize() >= 1 && _map == _rc->minimum(_rc->getRoot()))
						_map = _rc->getNull();
			}
			mapitrev(const mapitrev & src)
			: _rc(src._rc), _map(src._map), _compare(src._compare){}
			mapitrev & operator=(mapitrev const & rhs)
			{
				if (this != &rhs)
				{
					_rc = rhs._rc;
					_map = rhs._map;
					_compare = rhs._compare;
				}
				return (*this);
			}
			
			iterator_type base() const
			{
				return (++iterator(_rc, _map));
			}

			template<typename X, typename Y>
			friend bool operator==(const mapitrev<X> & lhs, const mapitrev<Y> & rhs)
			{
				return (lhs._map == rhs._map);
			}

			template<typename X, typename Y>
			friend bool operator!=(const mapitrev<X> & lhs, const mapitrev<Y> & rhs)
			{
				return (!(lhs == rhs));
			}

			mapitrev & operator++()
			{
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (_map->left != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->maximum(_map->left);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(_map->data.first, p->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullNode;
					else
						_map = p;
				}
				return (*this);
			}

			mapitrev operator++(int)
			{
				mapitrev old(*this);
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (_map->left != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->maximum(_map->left);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(_map->data.first, p->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullNode;
					else
						_map = p;
				}
				return (old);
			}

			mapitrev & operator--()
			{
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (_map == nullNode && _rc->getSize() >= 1)
					_map = _rc->minimum(_rc->getRoot());
				else if (((_map->left == nullNode && _map->right == nullNode)
						&& _map->parent == nullptr) || _map->parent == nullNode)
					_map = nullNode;
				else if (_map->parent && _compare(_map->data.first, _map->parent->data.first) && _map->right == nullNode)
					_map = _map->parent;
				else if (_map->right != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->minimum(_map->right);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(p->data.first, _map->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullptr;
					else
						_map = p;
				}
				return (*this);
			}

			mapitrev operator--(int)
			{
				mapitrev old(*this);
				NodePtr nullNode = _rc->getNull();
				if (_rc->getSize() == 0)
					_map = nullNode;
				else if (_map == nullNode && _rc->getSize() >= 1)
					_map = _rc->minimum(_rc->getRoot());
				else if (((_map->left == nullNode && _map->right == nullNode)
						&& _map->parent == nullptr) || _map->parent == nullNode)
					_map = nullNode;
				else if (_map->parent && _compare(_map->data.first, _map->parent->data.first) && _map->right == nullNode)
					_map = _map->parent;
				else if (_map->right != nullNode)
				{
					if (_rc->getSize() == 1)
						_map = _rc->getRoot();
					else
						_map = _rc->minimum(_map->right);
				}
				else
				{
					NodePtr p = _map->parent;
					while (p != nullptr && _compare(p->data.first, _map->data.first))
						p = p->parent;
					if (p == nullptr)
						_map = nullptr;
					else
						_map = p;
				}
				return (old);
			}

			const_reference operator*() const
			{
				return (_map->data);
			}

			const_pointer operator->() const
			{
				return (&_map->data);
			}
	};
}

#endif
