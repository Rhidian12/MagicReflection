#pragma once

#include <string>
#include <string_view>
#include <vector>

#define MRFL_GET_TYPE_NAME(object) MRFL::GetTypename<decltype(object)>()

#define MRFL_REFLECT_CLASS() friend class MRFL_ClassReflector;

#define MRFL_GET_VARIABLE_NAMES(object) 

#ifdef _MSC_VER
#define MRFL_FUNCTION_NAME __FUNCSIG__
#else
#define MRFL_FUNCTION_NAME __PRETTY_FUNCTION__
#endif

#define MRFL_CONSTEXPR constexpr
#define MRFL_NODISCARD [[nodiscard]]

namespace MRFL // MagicReFLection
{
	namespace Implementation
	{
		class MRFL_ClassReflector
		{
		public:

		private:

		};

		template<typename T>
		MRFL_NODISCARD MRFL_CONSTEXPR std::string_view GetFullTypename()
		{
			return MRFL_FUNCTION_NAME;
		}

		template<typename T>
		MRFL_NODISCARD MRFL_CONSTEXPR std::string_view GetFilteredTypename()
		{
			// This is pretty stupid.
			MRFL_CONSTEXPR static std::string_view FunctionName{ "MRFL::Implementation::GetFullTypename" };

			MRFL_CONSTEXPR static std::string_view FullName{ GetFullTypename<T>() };
			MRFL_CONSTEXPR static std::string_view FilteredName{ FullName.substr(FullName.find(FunctionName) + FunctionName.size()) };

			// FilteredName will look like:
			// <int, int>
			// <struct FooBar, int>
			// <int, class Map<struct FooBar, int>>

			return FilteredName.substr(1, FilteredName.find_last_of('>') - 1);
		}

		template<typename T>
		MRFL_NODISCARD MRFL_CONSTEXPR std::vector<std::string> GetAllVariableNames(const T& Object)
		{

		}
	} // Implementation

	template<typename T>
	MRFL_NODISCARD MRFL_CONSTEXPR std::string GetTypename()
	{
		return std::string{ Implementation::GetFilteredTypename<T>() };
	}

	template<typename T>
	MRFL_NODISCARD MRFL_CONSTEXPR std::vector<std::string> GetVariableNames(const T& Object)
	{
		return Implementation::GetAllVariableNames(Object);
	}
} // MRFL