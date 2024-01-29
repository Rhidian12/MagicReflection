#pragma once

#include <string>
#include <string_view>

#define MRFL_GET_TYPE_NAME(object) MRFL::GetTypename<decltype(object)>()

#ifdef _MSC_VER
#define MRFL_FUNCTION_NAME __FUNCSIG__
#else
#define MRFL_FUNCTION_NAME __PRETTY_FUNCTION__
#endif

#define MRFL_CONSTEXPR constexpr
#define MRFL_NODISCARD [[nodiscard]]
#define MRFL_MAX(a, b) a < b ? b : a

namespace MRFL // MagicReFLection
{
	namespace Implementation
	{
		template<typename T>
		MRFL_NODISCARD MRFL_CONSTEXPR static std::string_view GetFullTypename()
		{
			return MRFL_FUNCTION_NAME;
		}

		template<typename T>
		MRFL_NODISCARD MRFL_CONSTEXPR static std::string_view GetFilteredTypename()
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
	} // Implementation

	template<typename T>
	MRFL_NODISCARD MRFL_CONSTEXPR static std::string GetTypename()
	{
		return std::string{ Implementation::GetFilteredTypename<T>() };
	}
} // MRFL