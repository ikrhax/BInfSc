using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Assignment4Final;
using System.Windows.Forms;

namespace UnitTestProject1
{
    [TestClass]
    public class MethodsTesting
    {
        string[] TestSuperString = new string[] { "this", "is", "my", "test", "file", "for", "this", "assignment", "four", "test", "test", "test" };
        TextSearcher tsTest = new TextSearcher();
        TextHelper thTest = new TextHelper();

        [TestMethod]
        public void SearchByWordTest()
        {
            Assert.AreEqual(thTest.SearchByWord(TestSuperString.ToString()), 0);
        }

        [TestMethod]
        public void MostCommon()
        {
            Assert.AreEqual(thTest.MostCommon(TestSuperString.ToString()), 0);
        }

        [TestMethod]
        public void Appearances()
        {
            foreach (string item in TestSuperString)
            {
                thTest.AppearanceTally.Add(item, 1);
            }
            thTest.AppearanceTally["this"] = 2;
            Assert.AreEqual(thTest.MostCommon)
        }
    }
}
