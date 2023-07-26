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
        private void dgtvValues_CellValidating(object sender, DataGridViewCellValidatingEventArgs e)
        {
            // Check if the current column index is the one you want to validate (replace 1 with the actual column index)
            if (e.ColumnIndex >= 3 && e.ColumnIndex <= 8 && !string.IsNullOrEmpty(e.FormattedValue.ToString()))
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
            DataGridViewCell cellValues = dtgvValues.Rows[e.RowIndex].Cells[e.ColumnIndex];

            if (e.ColumnIndex >= 3)
            {
                if (int.TryParse(cellValues.Value?.ToString(), out int numericValue))
                {
                    switch (numericValue)
                    {
                        case 1:
                            cellValues.Style.BackColor = Color.Lime;
                            break;
                        case 2:
                            cellValues.Style.BackColor = Color.LimeGreen;
                            break;
                        case 3:
                            cellValues.Style.BackColor = Color.Yellow;
                            break;
                        case 4:
                            cellValues.Style.BackColor = Color.Orange;
                            break;
                        case 5:
                            cellValues.Style.BackColor = Color.Red;
                            break;
                        default:
                            break;
                    }
                }
            }
        }
        private void tabControl_Selected(object sender, TabControlEventArgs e)
        {
            for (int i = 0; i < dtgvRisks.Rows.Count; i++)
            {
                UpdateTab2(i);
                UpdateTab3(i);
                UpdateTab4(i);
            }
        }
        private void UpdateTab2(int i)
        {
            lblID.Text = txtID.Text;
            if (dtgvValues.Rows.Count < dtgvRisks.Rows.Count)
            {
                dtgvValues.Rows.Add();
            }
            dtgvValues.Rows[i].Cells[0].Value = dtgvRisks.Rows[i].Cells[2].Value;
            dtgvValues.Rows[i].Cells[1].Value = dtgvRisks.Rows[i].Cells[3].Value;
            dtgvValues.Rows[i].Cells[2].Value = dtgvRisks.Rows[i].Cells[4].Value;
        }
        private void UpdateTab3(int i)
        {
            int I = Convert.ToInt32(dtgvValues.Rows[i].Cells[3].Value) * Convert.ToInt32(dtgvValues.Rows[i].Cells[4].Value); //F*S
            int D = Convert.ToInt32(dtgvValues.Rows[i].Cells[5].Value) * Convert.ToInt32(dtgvValues.Rows[i].Cells[8].Value); //P*E
            int Pb = Convert.ToInt32(dtgvValues.Rows[i].Cells[6].Value) * Convert.ToInt32(dtgvValues.Rows[i].Cells[7].Value); //A*V
            int C = I + D;
            int ER = Pb * C;
            if (dtgvEvaluation.Rows.Count < dtgvValues.Rows.Count)
            {
                dtgvEvaluation.Rows.Add();
            }
            dtgvEvaluation.Rows[i].Cells[0].Value = dtgvValues.Rows[i].Cells[0].Value;
            dtgvEvaluation.Rows[i].Cells[1].Value = dtgvValues.Rows[i].Cells[1].Value;
            dtgvEvaluation.Rows[i].Cells[2].Value = dtgvValues.Rows[i].Cells[2].Value;
            dtgvEvaluation.Rows[i].Cells[3].Value = C;
            dtgvEvaluation.Rows[i].Cells[4].Value = Pb;
            dtgvEvaluation.Rows[i].Cells[5].Value = ER;
        }
        private void UpdateTab4(int i)
        {
            if (dtgvClassification.Rows.Count < dtgvEvaluation.Rows.Count)
            {
                dtgvClassification.Rows.Add();
            }
            dtgvClassification.Rows[i].Cells[0].Value = dtgvEvaluation.Rows[i].Cells[0].Value;
            dtgvClassification.Rows[i].Cells[1].Value = dtgvEvaluation.Rows[i].Cells[1].Value;
            dtgvClassification.Rows[i].Cells[2].Value = dtgvEvaluation.Rows[i].Cells[5].Value;

            DataGridViewCell ERValue = dtgvClassification.Rows[i].Cells[2];

            if (Convert.ToInt32(ERValue.Value) >= 2 && Convert.ToInt32(ERValue.Value) <= 250)
            {
                dtgvClassification.Rows[i].Cells[3].Value = "Muy Pequeño";
                dtgvClassification.Rows[i].Cells[3].Style.BackColor = Color.Lime;
            }
            else if (Convert.ToInt32(ERValue.Value) >= 251 && Convert.ToInt32(ERValue.Value) <= 500)
            {
                dtgvClassification.Rows[i].Cells[3].Value = "Pequeño";
                dtgvClassification.Rows[i].Cells[3].Style.BackColor = Color.LimeGreen;
            }
            else if (Convert.ToInt32(ERValue.Value) >= 501 && Convert.ToInt32(ERValue.Value) <= 750)
            {
                dtgvClassification.Rows[i].Cells[3].Value = "Normal";
                dtgvClassification.Rows[i].Cells[3].Style.BackColor = Color.Yellow;
            }
            else if (Convert.ToInt32(ERValue.Value) >= 751 && Convert.ToInt32(ERValue.Value) <= 1000)
            {
                dtgvClassification.Rows[i].Cells[3].Value = "Grande";
                dtgvClassification.Rows[i].Cells[3].Style.BackColor = Color.Orange;
            }
            else if (Convert.ToInt32(ERValue.Value) >= 1001 && Convert.ToInt32(ERValue.Value) <= 1250)
            {
                dtgvClassification.Rows[i].Cells[3].Value = "Elevado";
                dtgvClassification.Rows[i].Cells[3].Style.BackColor = Color.Red;
            }
            dtgvClassification.Sort(dtgvClassification.Columns[2], ListSortDirection.Descending);
        }

        public class RiskAnalysis
        {
            public string Analista { get; set; }
            public string Activo { get; set; }
            public string Riesgo { get; set; }
            public string Dano { get; set; }
            public string Clasificacion { get; set; }
            public int ID { get; set; }
            public int S { get; set; }
            public int F { get; set; }
            public int P { get; set; }
            public int A { get; set; }
            public int V { get; set; }
            public int E { get; set; }
            public int CR { get; set; }
            public int Pb { get; set; }
            public int ER { get; set; }         
        }
        using 
    }
}
    