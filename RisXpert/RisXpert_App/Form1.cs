using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.Remoting.Channels;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RisXpert_App
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            lblDate.Text = DateTime.Today.ToString();
        }

        private void btnNewRisk_Click(object sender, EventArgs e)
        {
            int _ = dtgvRisks.Rows.Add();
            UpdateData(sender, e);
        }
        private void UpdateData(object sender, EventArgs e)
        {
            for (int i = 0; i < dtgvRisks.Rows.Count; i++)
            {
                dtgvRisks.Rows[i].Cells[0].Value = txtID.Text;
                dtgvRisks.Rows[i].Cells[1].Value = txtAnalystName.Text;
                dtgvRisks.Rows[i].Cells[2].Value = txtActive.Text;
            }
        }
        private void ReloadTab2(object sender, TabControlEventArgs e)
        {
            lblID.Text = txtID.Text;
            for (int i = 0; i < dtgvRisks.Rows.Count; i++)
            {
                if (dtgvValues.Rows.Count < dtgvRisks.Rows.Count)
                {
                    dtgvValues.Rows.Add();
                }
                dtgvValues.Rows[i].Cells[0].Value = dtgvRisks.Rows[i].Cells[2].Value;
                dtgvValues.Rows[i].Cells[1].Value = dtgvRisks.Rows[i].Cells[3].Value;
                dtgvValues.Rows[i].Cells[2].Value = dtgvRisks.Rows[i].Cells[4].Value;
            }

        }

        private void dgtvValues_CellValidating(object sender, DataGridViewCellValidatingEventArgs e)
        {
            // Check if the current column index is the one you want to validate (replace 1 with the actual column index)
            if (e.ColumnIndex >= 3 && e.ColumnIndex <=8 && !string.IsNullOrEmpty(e.FormattedValue.ToString()))
            {
                // Try to parse the input value as an integer
                if (!int.TryParse(e.FormattedValue.ToString(), out int numericValue))
                {
                    e.Cancel = true; // Cancel the edit if the value is not numeric
                    MessageBox.Show("Inserte valor numérico.", "Valor no Válido", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    return;
                }

                // Check if the value is within the desired range (1 to 5)
                if (numericValue < 1 || numericValue > 5)
                {
                    e.Cancel = true; // Cancel the edit if the value is not within the desired range
                    MessageBox.Show("Inserte valor entre 1 y 5.", "Valor no Válido", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

        private void dtgvValues_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            DataGridViewCell cell = dtgvValues.Rows[e.RowIndex].Cells[e.ColumnIndex];
            if (e.ColumnIndex>=3)
            {
                if (int.TryParse(cell.Value?.ToString(), out int numericValue) && numericValue >= 1 && numericValue <= 5)
                {
                    // Assign the BackColor based on the numeric value
                    switch (numericValue)
                    {
                        case 1:
                            cell.Style.BackColor = Color.Lime;
                            break;
                        case 2:
                            cell.Style.BackColor = Color.LimeGreen;
                            break;
                        case 3:
                            cell.Style.BackColor = Color.Yellow;
                            break;
                        case 4:
                            cell.Style.BackColor = Color.Orange;
                            break;
                        case 5:
                            cell.Style.BackColor = Color.Red;
                            break;
                        default:
                            break;
                    }
                }
            }
        }


        /*private void dtgvValues_CellFormatting(object sender, DataGridViewCellFormattingEventArgs e)
{
   for (int i = 0; i<dtgvValues.Rows.Count; i++)
   {
       for (int j = 3; j< 8; j++)
       {
           switch (dtgvValues.Rows[i].Cells[j].Value.ToString())
           {
               case "1":
                   dtgvValues.Rows[i].Cells[j].Style.BackColor = Color.Green;
                   break;
               case "2":
                   dtgvValues.Rows[i].Cells[j].Style.BackColor = Color.GreenYellow;
                   break;
               case "3":
                   dtgvValues.Rows[i].Cells[j].Style.BackColor = Color.Yellow;
                   break;
               case "4":
                   dtgvValues.Rows[i].Cells[j].Style.BackColor = Color.Orange;
                   break;
               case "5":
                   dtgvValues.Rows[i].Cells[j].Style.BackColor = Color.Red;
                   break;
               default:
                   return;
*/
    }
}
    