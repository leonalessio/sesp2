
#include <pwm.h>
#include <gtest/gtest.h>


TEST(test_pass, invalid_pass_length5) {
  ASSERT_EQ(PWM_INVALID_PASSWORD, pwm_is_valid_password("Aa9zx"));
}

TEST(test_pass, valid_pass_length6) {
  ASSERT_EQ(PWM_OK, pwm_is_valid_password("Aa9za1"));
}

TEST(test_pass, invvalid_pass_with_two_punct) {
  ASSERT_EQ(PWM_INVALID_PASSWORD, pwm_is_valid_password("Aa9za1!!"));
}

TEST(test_pass, blacklisted_pass1) {
  ASSERT_EQ(PWM_INVALID_PASSWORD, pwm_is_valid_password("A123zad!"));
}
// etc ...

TEST(test_pass, valid_pass_with_one_punct) {
  ASSERT_EQ(PWM_OK, pwm_is_valid_password("Aa9za1!"));
}

TEST(test_pass, invalid_pass_no_uppercase) {
  ASSERT_EQ(PWM_INVALID_PASSWORD, pwm_is_valid_password("aa9za1"));
}

TEST(test_pass, invalid_pass_no_lowercase) {
  ASSERT_EQ(PWM_INVALID_PASSWORD, pwm_is_valid_password("AA9ZA1"));
}

TEST(test_pass, invalid_pass_no_digit) {
  ASSERT_EQ(PWM_INVALID_PASSWORD, pwm_is_valid_password("Aazabc!"));
}

TEST(test_pass, invalid_pass_length12) {
  ASSERT_EQ(PWM_OK, pwm_is_valid_password("Aa9za1bcdefg"));
}

TEST(test_pass, invalid_pass_length13) {
  ASSERT_EQ(PWM_INVALID_PASSWORD, pwm_is_valid_password("Aa9za1bcdefgh"));
}

TEST(test_pass, valid_pass_weird_char) {
  ASSERT_EQ(PWM_OK, pwm_is_valid_password("Aaz$1zA"));
}

TEST(test_pass, invalid_pass_weird_char) {
  ASSERT_EQ(PWM_INVALID_PASSWORD, pwm_is_valid_password("Aaz$!!"));
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
