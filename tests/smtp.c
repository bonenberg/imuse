/*
 * Testing for the smtp sending code
 */
#include <stdio.h>
#include <glib.h>
#include <imap/c-client.h>

#include <CUnit/Basic.h>

void mm_flags(MAILSTREAM *stream, unsigned long number) { printf("Calling mm_flags\n"); return; }
void mm_status(MAILSTREAM *stream, char *mailbox, MAILSTATUS *status) { printf("Calling mm_status\n"); return; }
void mm_searched(MAILSTREAM *stream, unsigned long number) { printf("Calling mm_searched\n"); return; }
void mm_exists(MAILSTREAM *stream, unsigned long number) { printf("Calling mm_exists\n"); return; }
void mm_expunged(MAILSTREAM *stream, unsigned long number) { printf("Calling mm_expunged\n"); return; }
void mm_list(MAILSTREAM *stream, int delim, char *name, long attrib) { printf("Calling mm_list\n"); return; }
void mm_log(char *string,long errflg) { printf("Calling mm_log\n"); return; }
void mm_lsub(MAILSTREAM *stream,int delimiter,char *name,long attributes) { printf("Calling mm_lsub\n"); return; }
void mm_fatal(char *string) { printf("Calling mm_fatal\n"); return; }
long mm_diskerror(MAILSTREAM *stream,long errcode,long serious) { printf("Calling mm_diskerror\n"); return 0L; }
void mm_dlog(char *string) { printf("Calling mm_dlog\n"); }
void mm_notify(MAILSTREAM *stream,char *string,long errflg) { printf("Calling mm_notify\n"); return; }
void mm_critical(MAILSTREAM *stream) { printf("Calling mm_critical\n"); return; }
void mm_nocritical(MAILSTREAM *stream) { printf("Calling mm_nocritical\n"); return;}
void mm_login(NETMBX *mb,char *user,char *pwd,long trial) { printf("Calling mm_login\n"); return; }

void test_Void() {
	CU_ASSERT(TRUE == TRUE);
}

void test_BasicSendMail() {
	char *server = "smtp.slide.com";
	char *servers[] = {server};
	long smtp_options = 0L;

	SENDSTREAM *sendstream = smtp_open(servers, smtp_options);
	CU_ASSERT_PTR_NOT_NULL(sendstream);

}

int main() {
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Smtp_Suite", NULL, NULL);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if (
		(NULL == CU_add_test(pSuite, "empty test", test_Void)) 
	  )
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}
