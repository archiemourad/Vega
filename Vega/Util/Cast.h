#pragma once
#include <vector>
#include <memory>

namespace Vega
{
	namespace Util
	{
		template <typename T>
		class Cast
		{
		public:
			/// <summary>
			/// Add a member to the cast.
			/// </summary>
			/// <param name="member"></param>
			/// <returns>A shared pointer pointing to the member.</returns>
			std::shared_ptr<T> AddMember(T member);

			/// <summary>
			/// Remove a member from the cast.
			/// </summary>
			/// <param name="ptr"></param>
			void RemoveMember(std::shared_ptr<T> ptr);

			// Getters & Setters.

			std::vector<std::shared_ptr<T>> GetMembers() { return members; }
			void SetMembers(std::vector<std::shared_ptr<T>> members) { this->members = members; }

		private:
			std::vector<std::shared_ptr<T>> members;

		};

		template<typename T>
		inline std::shared_ptr<T> Cast<T>::AddMember(T member)
		{
			std::shared_ptr<T> ptr = std::make_shared<T>(member);

			members.push_back(ptr);

			return ptr;
		}

		template<typename T>
		inline void Cast<T>::RemoveMember(std::shared_ptr<T> ptr)
		{
			members.erase(
				std::remove_if(
					members.begin(),
					members.end(),
					[ptr](std::shared_ptr<T> lptr) { return (ptr == lptr); }
				),

				members.end()
			);
		}
	}
}

