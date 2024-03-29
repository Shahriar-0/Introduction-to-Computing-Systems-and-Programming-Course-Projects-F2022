#define _CRT_SECURE_NO_WARNINGS
#include "user_handler.h"
#include "handling_datas.h"

int main() {
	User* list_of_users = NULL;
	Hall* list_of_halls = NULL;
	Food* list_of_foods = NULL;
	Coupon* list_of_coupons = NULL;
	int size_of_users = 0, size_of_foods = 0, size_of_halls = 0, size_of_coupons = 0, mode = CONTINUE;

	load_users(&list_of_users, &size_of_users);
	load_halls(&list_of_halls, &size_of_halls);
	load_foods(&list_of_foods, &size_of_foods);
	load_coupons(&list_of_coupons, &size_of_coupons);

	bool user = LOG_OUT, admin = LOG_OUT;

	printf("welcome! this app will help you with your food reservation.\nto shut the app at any given time, simply type terminate\n**********************************************************\n");
	while (1) {
		while (!user && !admin) {

			mode = enetring_app(&list_of_users, &size_of_users, &user, &admin);
			if (mode == TERMINATE) {
				freeing(list_of_users, size_of_users, list_of_foods, size_of_foods, list_of_halls, size_of_halls, list_of_coupons, size_of_coupons);
				exit(EXIT_SUCCESS);
			}		
		}
		
		while (user) {
			mode = get_order_from_user(&user);
			if (mode == TERMINATE) {
				freeing(list_of_users, size_of_users, list_of_foods, size_of_foods, list_of_halls, size_of_halls, list_of_coupons, size_of_coupons);
				exit(EXIT_SUCCESS);
			}
		}

		while (admin){
			mode = get_order_from_admin(&list_of_foods, &size_of_foods, &list_of_halls, &size_of_halls, &list_of_coupons, &size_of_coupons, &admin);
			if (mode == TERMINATE) {
				freeing(list_of_users, size_of_users, list_of_foods, size_of_foods, list_of_halls, size_of_halls, list_of_coupons, size_of_coupons);
				exit(EXIT_SUCCESS);
			}
		}
	}
	return 0;
}