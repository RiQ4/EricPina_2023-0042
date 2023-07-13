using LiteDB;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Prueba_LiteDB
{
    internal class Program
    {
        static void Main(string[] args)
        {
            using (var db = new LiteDatabase(@"C:\Users\HP\Documents\ITLA\Tareas\PPM\Repositorio\EricPina_2023-0042\Prueba LiteDB\MyData.db"))
            {
              
                var col = db.GetCollection<Customer>("customers");

              
                var customer = new Customer
                {
                    Name = "Random Pina",
                    Phones = new string[] { "8000-0000", "9000-0000" },
                    IsActive = true
                };
                col.Insert(customer);

              
                customer.Name = "Literally Me";

                col.Update(customer);

             
                col.EnsureIndex(x => x.Name);

              
                var results = col.Query()
                    .Where(x => x.Name.StartsWith("J"))
                    .OrderBy(x => x.Name)
                    .Select(x => new { x.Name, NameUpper = x.Name.ToUpper() })
                    .Limit(10)
                    .ToList();

            
                col.EnsureIndex(x => x.Phones);

           
                var r = col.FindOne(x => x.Phones.Contains("8888-5555"));
            }
        }
        }
        public class Customer
        {
            public int Id { get; set; }
            public string Name { get; set; }
            public string[] Phones { get; set; }
            public bool IsActive { get; set; }
        }
    }

