#pragma once
#include <string>
#include "circuitelement.h"

namespace spiceSimulator {

	class Branch :
		public CircuitElement
	{
	public:

		friend class BranchStorage;

		Branch(void);
		Branch(unsigned long);
		~Branch(void);
		unsigned long getBranchNumber();
		

	private:
		void setBranchNumber(unsigned long);
		unsigned long identifier; //the identifier of the component
		unsigned long branchNumber; //holds the position this Branch is on the equation matrix
	};
	 
}