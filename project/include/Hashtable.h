/* Exit Games Common - C++ Client Lib
 * Copyright (C) 2004-2013 by Exit Games GmbH. All rights reserved.
 * http://www.exitgames.com
 * mailto:developer@exitgames.com
 */

#ifndef __HASHTABLE_H
#define __HASHTABLE_H

#include "KeyObject.h"
#include "ValueObject.h"
#include "JVector.h"

namespace ExitGames
{
	namespace Common
	{
		template<typename Etype> class KeyObject;

		class Hashtable : public Base
		{
		public:
			using ToString::toString;

			Hashtable(void);
			~Hashtable(void);

			Hashtable(const Hashtable& toCopy);
			Hashtable& operator=(const Hashtable& toCopy);

			bool operator==(const Hashtable& toCompare) const;
			bool operator!=(const Hashtable& toCompare) const;
			const Object& operator[](unsigned int index) const;
			Object& operator[](unsigned int index);

			void put(const Hashtable& src);
			template<typename FKeyType, typename FValueType> void put(const FKeyType& key, const FValueType& val);
			template<typename FKeyType> void put(const FKeyType& key);
			template<typename FKeyType, typename FValueType> void put(const FKeyType& key, const FValueType pVal, short size);
			template<typename FKeyType, typename FValueType> void put(const FKeyType& key, const FValueType pVal, const short* const sizes);

			template<typename FKeyType> const Object* getValue(const FKeyType& key) const;
			unsigned int getSize(void) const;
			const JVector<Object>& getKeys(void) const;
			template<typename FKeyType> void remove(const FKeyType& key);
			template<typename FKeyType> bool contains(const FKeyType& key) const;
			void removeAllElements(void);
			JString& toString(JString& retStr, bool withTypes=false) const;
		private:
			static bool haveSameKey(const Object& one, const Object& two);

			void putImplementation(const Object& key, const Object& val);
			const Object* getValueImplementation(const Object& key) const;
			void removeImplementation(const Object& key);
			bool containsImplementation(const Object& key) const;

			class KeyToObject
			{
			public:
				template<typename Ftype> static Object get(Ftype key){return KeyObject<Ftype>(key);}
				static Object get(Object key){return key;}
				static Object get(const char* key){return get(JString(key));}
				static Object get(const wchar_t* key){return get(JString(key));}
			};
			class ValueToObject
			{
			public:
				template<typename Ftype> static Object get(Ftype value){return ValueObject<Ftype>(value);}
				static Object get(Object value){return value;}
				static Object get(const char* value){return ValueToObject::get(JString(value));}
				static Object get(const wchar_t* value){return ValueToObject::get(JString(value));}
				template<unsigned int N> static Object get(const char value[N]){return ValueToObject::get(JString(value));}
				template<unsigned int N> static Object get(const wchar_t value[N]){return ValueToObject::get(JString(value));}
				template<typename Ftype> static Object get(Ftype* pValue, short size){return ValueObject<Ftype*>(pValue, size);}
				static Object get(char** pValue, short size){return stringArrayHelper(pValue, size);}
				static Object get(const char** pValue, short size){return stringArrayHelper(pValue, size);}
				static Object get(wchar_t** pValue, short size){return stringArrayHelper(pValue, size);}
				static Object get(const wchar_t** pValue, short size){return stringArrayHelper(pValue, size);}
				template<typename Ftype> static Object get(Ftype** pValue, const short* sizes){return ValueObject<Ftype**>(pValue, sizes);}
			private:
				template<typename Ftype> static Object stringArrayHelper(Ftype** pValue, short size){JString* pArr = MemoryManagement::allocateArray<JString>(size);for(short i=0;i<size;++i)pArr[i] = pValue[i];Object retVal= ValueObject<JString*>(pArr, size); MemoryManagement::deallocateArray(pArr); return retVal;}
			};

			JVector<Object> mKeytable;
			JVector<Object> mValtable;
		};



		/** 
		   Adds a pair of a key and a corresponding value to the instance.
		   @details
		   If the key is already existing, then it's old value will be
		   replaced with the new one.
		   Please have a look at the @link Datatypes table of datatypes\endlink for a list of supported types for keys and values
		   @param key the key to add
		   @param val the value to add
		   @returns
		   nothing. */
		template<typename FKeyType, typename FValueType>
		void Hashtable::put(const FKeyType& key, const FValueType& val)
		{
			typename Helpers::ConfirmAllowedKey<FKeyType>::type forceCompilationToFailForUnsupportedKeyTypes; (void)forceCompilationToFailForUnsupportedKeyTypes;
			typename Helpers::ConfirmAllowed<FValueType>::type forceCompilationToFailForUnsupportedValueTypes; (void)forceCompilationToFailForUnsupportedValueTypes;
			COMPILE_TIME_ASSERT2_TRUE_MSG(!Helpers::ConfirmAllowed<typename Helpers::ConfirmAllowed<FValueType>::type>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_SINGLE_VALUES);
			putImplementation(KeyToObject::get(key), ValueToObject::get(val));
		}

		/** @overload
		    @details
			This overload will add an empty object as value for the provided key. */
		template<typename FKeyType>
		void Hashtable::put(const FKeyType& key)
		{
			putImplementation(KeyToObject::get(key), Object());
		}

		/** @overload 
		    @details
			This overload accepts singledimensional arrays and NULL-pointers passed for parameter val.
		    @param key the key to add
		    @param pVal the value array to add
			@param size the size of the value array */
		template<typename FKeyType, typename FValueType>
		void Hashtable::put(const FKeyType& key, const FValueType pVal, short size)
		{
			typename Helpers::ConfirmAllowedKey<FKeyType>::type forceCompilationToFailForUnsupportedKeyTypes; (void)forceCompilationToFailForUnsupportedKeyTypes;
			typename Helpers::ConfirmAllowed<FValueType>::type forceCompilationToFailForUnsupportedValueTypes; (void)forceCompilationToFailForUnsupportedValueTypes;
			COMPILE_TIME_ASSERT2_TRUE_MSG(Helpers::ConfirmAllowed<typename Helpers::ConfirmAllowed<FValueType>::type>::dimensions==1, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_1D_ARRAYS);
			putImplementation(KeyToObject::get(key), ValueToObject::get(pVal, size));
		}

		/** @overload 
		    @details
			This overload accepts multidimensional arrays and NULL-pointers passed for parameter val.
			The array, passed for parameter val has to be a pointer of the correct abstraction level, meaning a normal pointer for
			a singledimensional array, a doublepointer for a twodimensional array, a triplepointer for a threedimensional array and so
			on.
		    @param key the key to add
		    @param pVal the value array to add
			@param sizes the sizes of the value array for every dimension */
		template<typename FKeyType, typename FValueType>
		void Hashtable::put(const FKeyType& key, const FValueType pVal, const short* const sizes)
		{
			typename Helpers::ConfirmAllowedKey<FKeyType>::type forceCompilationToFailForUnsupportedKeyTypes; (void)forceCompilationToFailForUnsupportedKeyTypes;
			typename Helpers::ConfirmAllowed<FValueType>::type forceCompilationToFailForUnsupportedValueTypes; (void)forceCompilationToFailForUnsupportedValueTypes;
			COMPILE_TIME_ASSERT2_TRUE_MSG((bool)Helpers::ConfirmAllowed<typename Helpers::ConfirmAllowed<FValueType>::type>::dimensions, ERROR_THIS_OVERLOAD_IS_ONLY_FOR_FOR_ARRAYS);
			putImplementation(KeyToObject::get(key), ValueToObject::get(pVal, sizes));
		}


		
		/**
		   Deletes the specified key and the corresponding value, if
		   found in the Hashtable.
		   @param key Pointer to the key of the key/value-pair to remove.
		   @returns
		   nothing.
		   @sa
		   removeAllElements()    */
		template<typename FKeyType>
		void Hashtable::remove(const FKeyType& key)
		{
			removeImplementation(KeyToObject::get(key));
		}
		
		/**
		   Checks, whether the Hashtable contains a certain key.
		   @param key Pointer to the key to look up.
		   @returns
		   true if the specified key was found, false otherwise. */
		template<typename FKeyType>
		bool Hashtable::contains(const FKeyType& key) const
		{
			return containsImplementation(KeyToObject::get(key));
		}

		/**
		   Returns the corresponding value for a specified key.
		   @param key  Reference to the key to return the corresponding value for.
		   @returns
		   a pointer to the corresponding value if the Hashtable
		   contains the specified key, NULL otherwise.
		   
		   @sa
		   put()                                                               */
		template<typename FKeyType>
		const Object* Hashtable::getValue(const FKeyType& key) const
		{
			return getValueImplementation(KeyToObject::get(key));
		}
	}
}

#endif