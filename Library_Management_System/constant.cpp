#include "constant.h"

namespace Constant
{
	void Init(){
		ADMIN_ACCESS.ADD_USER = true;
		ADMIN_ACCESS.BOLLOW_BOOK = true;
		ADMIN_ACCESS.BOLLOW_HISTORY = true;
		ADMIN_ACCESS.CHANGE_PASSWORD = true;
		ADMIN_ACCESS.DELETE_USER = true;
		ADMIN_ACCESS.RENEW_BOOK = true;
		ADMIN_ACCESS.RESET_PASSWORD = true;
		ADMIN_ACCESS.RETURN_BOOK = true;
		ADMIN_ACCESS.SEARCH_BOOK = true;

		NORMAL_ACCESS.ADD_USER = false;
		NORMAL_ACCESS.BOLLOW_BOOK = false;
		NORMAL_ACCESS.BOLLOW_HISTORY = true;
		NORMAL_ACCESS.CHANGE_PASSWORD = true;
		NORMAL_ACCESS.DELETE_USER = false;
		NORMAL_ACCESS.RENEW_BOOK = false;
		NORMAL_ACCESS.RESET_PASSWORD = false;
		NORMAL_ACCESS.RETURN_BOOK = false;
		NORMAL_ACCESS.SEARCH_BOOK = true;
	}
}