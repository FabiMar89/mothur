/*
 *  goodscoverage.cpp
 *  Mothur
 *
 *  Created by Thomas Ryabin on 4/8/09.
 *  Copyright 2009 Schloss Lab UMASS Amherst. All rights reserved.
 *
 */

#include "goodscoverage.h"
#include "calculator.h"

/**********************************************************/

EstOutput GoodsCoverage::getValues(SAbundVector* rank){
	try {
		data.resize(1,0);
		
		double numSingletons = rank->get(1);
		double totalIndividuals = rank->getNumSeqs();
		
		data[0] = 1 - numSingletons/totalIndividuals;
		
		if (isnan(data[0]) || isinf(data[0])) { data[0] = 0; }

		return data;
	}
	catch(exception& e) {
		cout << "Standard Error: " << e.what() << " has occurred in the GoodsCoverage class Function getValues. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}
	catch(...) {
		cout << "An unknown error has occurred in the GoodsCoverage class function getValues. Please contact Pat Schloss at pschloss@microbio.umass.edu." << "\n";
		exit(1);
	}	
}

/***********************************************************************/

