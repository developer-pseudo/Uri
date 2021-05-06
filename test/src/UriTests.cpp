/**
 * @file UriTests.cpp
 *
 * This module contains the unit tests of the Uri::Uri class.
 *
 * © 2021 by developer-pseudo
 */

#include <gtest/gtest.h>
#include <Uri/Uri.hpp>

TEST(UriTests, ParseFromStringUrl) {
    Uri::Uri uri;

    ASSERT_TRUE(uri.ParseFromString("http://www.example.com/foo/bar"));
    ASSERT_EQ("http", uri.GetScheme());
    ASSERT_EQ("www.example.com", uri.GetHost());
    ASSERT_EQ(
        (std::vector< std::string >{
            "",
            "foo",
            "bar",
        }),
        uri.GetPath()
    );
}

TEST(UriTests, ParseFromStringUrnDefaultPathDelimiter) {
    Uri::Uri uri;

    ASSERT_TRUE(uri.ParseFromString("urn:book:fantasy:Hobbit"));
    ASSERT_EQ("urn", uri.GetScheme());
    ASSERT_EQ("", uri.GetHost());
    ASSERT_EQ(
        (std::vector< std::string >{
            "book:fantasy:Hobbit",
        }),
        uri.GetPath()
    );
}

TEST(UriTests, ParseFromStringUrnSingleCharacterPathDelimiter) {
    Uri::Uri uri;
    uri.setPathDelimiter(":");
    ASSERT_TRUE(uri.ParseFromString("urn:book:fantasy:Hobbit"));
    ASSERT_EQ("urn", uri.GetScheme());
    ASSERT_EQ("", uri.GetHost());
    ASSERT_EQ(
        (std::vector< std::string >{
            "book",
            "fantasy",
            "Hobbit",
        }),
        uri.GetPath()
    );
}

TEST(UriTests, ParseFromStringUrnMultiCharacterPathDelimiter) {
    Uri::Uri uri;
    uri.setPathDelimiter("/-");
    ASSERT_TRUE(uri.ParseFromString("urn:bo-/ok/-fant/asy/-Hob-bit"));
    ASSERT_EQ("urn", uri.GetScheme());
    ASSERT_EQ("", uri.GetHost());
    ASSERT_EQ(
        (std::vector< std::string >{
            "bo-/ok",
            "fant/asy",
            "Hob-bit",
        }),
        uri.GetPath()
    );
}
