using System;
using System.IO;

class Program
{
    static async Task Main(string[] args)
    {
        string[] testStrs = {
    "  hello, world!  ",
    "   foo bar ",
    "  \t   test\t\t",
    "",
    " ",
    " \n\r\f\v ",
    " This is a longer string with multiple spaces and tabs     \t \t  ",
    "This string has no spaces or tabs",
    "   ",
    " \t"
};
string trimChars = " \t\n\r\f\v";
string insertChars = "INSERT ME PLZ ^_^";

// Loop through the test strings and write the trimmed versions to file
foreach (string testStr in testStrs)
{
    string trimmedStr = testStr.Trim(trimChars.ToCharArray());
    string[] lines = {
        $"Original string: '{testStr}'\nTrimed string: '{trimmedStr}'\n"
    };
    await File.AppendAllLinesAsync("cs_trim.txt", lines);
}

// Loop through the test strings again and insert the insertChars string at the beginning of each
for (int i = 0; i < testStrs.Length; i++)
{
    string insertStr = insertChars + testStrs[i];
    string[] lines = {
        $"Original string: '{testStrs[i]}'\nInserted string: '{insertStr}'\n"
    };
    await File.AppendAllLinesAsync("cs_insert.txt", lines);
}
    }
}