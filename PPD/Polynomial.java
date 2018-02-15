import mpi.*;
import java.util.Arrays;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.ObjectOutput;
import java.io.ObjectInput;
import java.io.InvalidObjectException;
import java.io.IOException;
import java.lang.Exception;
import java.util.List;
import java.util.ArrayList;
import java.util.Random;
import java.util.Arrays;



public class Polynomial implements java.io.Serializable {
		public int _degree;
		public int[] _coefficients;
		public static Random R = new Random();
		public static class BytesUtil {

    // toByteArray and toObject are taken from: http://tinyurl.com/69h8l7x
    	public byte[] toByteArray(Object obj) { 
	    	byte[] bytes = null;
	    	ByteArrayOutputStream bos = null;
	    	ObjectOutputStream oos = null;
	   		 try {
	       		bos = new ByteArrayOutputStream();
	        	oos = new ObjectOutputStream(bos);
	        	oos.writeObject(obj);
	        	oos.flush();
	        	bytes = bos.toByteArray();
	    		} catch(Exception e) {
	    			System.out.println("I don't caaare about bytes");
	    		}
	    		finally {
	    			try {
		        		if (oos != null) {
		        		
		            		oos.close();

		        		}
		        		if (bos != null) {
		            		bos.close();
		        		}
	        		} catch(IOException e) {

	        		}
	    	}
	    	return bytes;
		}

	    public Object toObject(byte[] bytes) {
	        Object obj = null;
	        ByteArrayInputStream bis = null;
	        ObjectInputStream ois = null;
	        try {
	            bis = new ByteArrayInputStream(bytes);
	            ois = new ObjectInputStream(bis);
	            obj = ois.readObject();
	        }
	        catch (Exception e) {
	        	System.out.println("I don't caaare about objects");


	        } finally {
	        	try {
		            if (bis != null) {
		                bis.close();
		            }
		            if (ois != null) {
		                ois.close();
		            }
	        	} catch (IOException e) {

	        	}
	        }
	        return obj;
	    	}
		}

		 public Polynomial(int[] coefficients)
        {

            _degree = coefficients.length - 1;
            _coefficients = coefficients;
        }

        public static Polynomial MultiplyKaratsuba(Polynomial x, Polynomial y) throws InvalidObjectException {
        if (x._degree != y._degree)
            throw new InvalidObjectException("Only works for polynomials of same degree!");

        int d = Math.min(x._degree, y._degree);
        int n = d + 1;

        int[] di = new int[n];
        int[][] dpq = new int[n][n];

        for (int i = 0; i <= n - 1; ++i)
            di[i] = x._coefficients[i] * y._coefficients[i];

        for (int i = 0; i <= 2 * n - 3; ++i)
            for (int p = 0; p <= i; ++p)
            {
                int q = i - p;
                if (p < n && q < n && q > p)
                    dpq[p][q] = (x._coefficients[p] + x._coefficients[q]) * (y._coefficients[p] + y._coefficients[q]);
            }

        int[] result = new int[2 * n - 1];

        result[0] = di[0];
        result[2 * n - 2] = di[n - 1];
        for (int i = 1; i <= 2 * n - 3; ++i)
        {
            for (int p = 0; p <= i; ++p)
            {
                int q = i - p;
                if (p < n && q < n && q > p)
                    result[i] += dpq[p][q] - (di[p] + di[q]);
            }

            if (i % 2 == 0)
                result[i] += di[i / 2];
        }

        return new Polynomial(result);
    }

        public static Polynomial Multiply(Polynomial a, Polynomial b) throws InvalidObjectException {
        	int[] coefficients = new int[a._degree + b._degree + 1];

        	for (int i = 0; i <= a._degree; ++i)
            	for (int j = 0; j <= b._degree; ++j)
                	coefficients[i + j] += a._coefficients[i] * b._coefficients[j];

        	return new Polynomial(coefficients);
    	}



    	@Override
    	public String toString() {

        	StringBuilder sb = new StringBuilder();

       		 for (int i = 0; i <= _degree; ++i)
            sb.append(String.format("%s%d*X^%d", _coefficients[i] >= 0 ? "+" : "", _coefficients[i], i));

        	return sb.toString();
    	}

		 public static class VectorElement implements java.io.Serializable {
		 	VectorElement() {}
		 	VectorElement(int index, int value) {
		 		Index = index;
		 		Value = value;
		 	}
        	public int Index;
        	public int Value;
    	}
    	 public static class MatrixElement implements java.io.Serializable  {
    	 	MatrixElement() {}
    	 	MatrixElement(int row, int column, int value) {
    	 		_row = row;
    	 		_column = column;
    	 		_value = value;
    	 	}
        	public int _row;
            public int _column;
            public int _value;
    	}
    	public static class Pair {
    		public int _first;
    		public int _end;
    		Pair(int first, int end) {
    			_first = first;
    			_end = end;
    		}
    	}
    	 private static List<Integer> DivideEvenly(int numerator, int denominator) throws Exception
        {
            if (numerator <= 0 || denominator <= 0)
                throw new Exception("Invalid division!");
            List<Integer> array = new ArrayList<>();
            int mod;
            int div = numerator / denominator;
            mod = numerator % denominator;

            for (int i = 0; i < denominator; i++) {
            	if(i < mod) {
            		array.add(div + 1);
            	} else {
            		array.add(div);
            	}
            }
            return array;
            	
        }
    	 private static Pair MpiFor(int forStart, int forEnd, int forIncrement, Intracomm communicator)
    	
      	{
            int forIterations = (forEnd - forStart) / forIncrement + 1;

            int workers = communicator.Size() - 1;
            List<Integer> workload = new ArrayList<>();
            try {
            	workload = DivideEvenly(forIterations, workers);
            }
            catch(Exception e) {
            	System.out.println(e);
            }	
            int workloadStart = 0;
            int workloadEnd = workload.get(0) - 1;

            for (int i = 1; i < communicator.Rank(); ++i)
            {
                workloadStart += workload.get(i - 1);
                workloadEnd = workloadStart + workload.get(i) - 1;
            }
            return new Pair(workloadStart, workloadEnd);
        }

	    public static Polynomial RandomPolynomial(int degree) throws InvalidObjectException {
	        if (degree < 0)
	            throw new InvalidObjectException("Invalid degree specification!");

	        int[] coefficients = new int[degree + 1];

	        for (int i = 0; i <= degree; ++i)
	            coefficients[i] = R.nextInt(10);
		    return new Polynomial(coefficients);
    	}


       public static void Karatsuuuba(String[] args) throws InvalidObjectException {
       		MPI.Init(args);
 
			Request req;
			byte[] src1 = new byte[10000];
			byte[] src2 = new byte[10000];

			byte[] dest1 = new byte[10000];
			byte[] dest2 = new byte[10000];

			byte[] v1 = new byte[1000];
			byte[] v2 = new byte[10000];

			Polynomial x = null, y = null;
            int n = 0;


			BytesUtil bytesUtil = new BytesUtil();

  			final int degree = 100;
             try {
            	x = RandomPolynomial(degree);
            	y = RandomPolynomial(degree);
        	} catch(InvalidObjectException e) {
        		System.out.println();
        	}
	       
	     	src1 = bytesUtil.toByteArray(x);
	     	src2 = bytesUtil.toByteArray(y);
    	 	if (MPI.COMM_WORLD.Rank() == 0) {

	    	 	
	             n = degree + 1;

	            int[] di = new int[n];
	            int[][] dpq = new int[n][n];
	            int d = 1;
                 MPI.COMM_WORLD.Bcast(src1, 0, src1.length, MPI.BYTE, 0);
                 MPI.COMM_WORLD.Bcast(src2, 0, src2.length, MPI.BYTE, 0);

                 for (int i = 1; i <= n; ++i)
                 {
                 		
                 		req = MPI.COMM_WORLD.Irecv(v1, 0, v1.length , MPI.BYTE, MPI.ANY_SOURCE, 999);
                 		req.Wait();
                 		VectorElement result = (VectorElement) bytesUtil.toObject(v1);
                        di[result.Index] = result.Value;
                 }




               	for (int i = 1; i <= n * (n - 1) / 2; ++i) {
                        req = MPI.COMM_WORLD.Irecv(v2, 0, v2.length, MPI.BYTE, MPI.ANY_SOURCE, 998);
                        req.Wait();
                        MatrixElement result = (MatrixElement) bytesUtil.toObject(v2);
                        dpq[result._row][result._column] = result._value;
                 }
		        int[] result = new int[2 * n - 1];

		        result[0] = di[0];
		        result[2 * n - 2] = di[n - 1];
		        for (int i = 1; i <= 2 * n - 3; ++i)
		        {
		            for (int p = 0; p <= i; ++p)
		            {
		                int q = i - p;
		                if (p < n && q < n && q > p)
		                    result[i] += dpq[p][q] - (di[p] + di[q]);
		            }

		            if (i % 2 == 0)
		                result[i] += di[i / 2];
		        }

                Polynomial output = new Polynomial(result);
                System.out.println(Arrays.equals(output._coefficients, MultiplyKaratsuba(x,y)._coefficients));
     	}

     	else  {
     		     MPI.COMM_WORLD.Bcast(dest1, 0, src1.length, MPI.BYTE, 0);
              MPI.COMM_WORLD.Bcast(dest2, 0, src2.length, MPI.BYTE, 0);
      		 Polynomial poly1 = (Polynomial) bytesUtil.toObject(dest1);
      		 Polynomial poly2 = (Polynomial) bytesUtil.toObject(dest2);
  			 n = Math.min(x._degree, y._degree) + 1;

             Pair pair1 = MpiFor(0, n - 1, 1, MPI.COMM_WORLD);
                   
             for (int i = pair1._first; i <= pair1._end; ++i) {
                	v1 = bytesUtil.toByteArray(new VectorElement (i, poly1._coefficients[i] * poly2._coefficients[i]));
                	req = MPI.COMM_WORLD.Isend(v1, 0, v1.length, MPI.BYTE, 0, 999);
                	req.Wait();
              }

              Pair pair2 = MpiFor(0, 2 * n - 3, 1, MPI.COMM_WORLD);
              for (int i = pair2._first; i <= pair2._end; ++i) {
                	for (int p = 0; p <= i; ++p)
                	{
                    	int q = i - p;
                    	if (p < n && q < n && q > p) {
                    		v2 = bytesUtil.toByteArray(new MatrixElement(p, q, (poly1._coefficients[p] + poly1._coefficients[q]) * (poly2._coefficients[p] + poly2._coefficients[q])));
                  
                        	req = MPI.COMM_WORLD.Isend(v2, 0, v2.length, MPI.BYTE, 0, 998);
                        	req.Wait();
                        }  	
                        	
                	}
                }
	    }

    	MPI.COMM_WORLD.Barrier();
    	MPI.Finalize();

       }
       public static void NormalMultiplicationMPI(String[] args)  throws InvalidObjectException  {
       		MPI.Init(args);
 
			Request req;
			byte[] src1 = new byte[10000];
			byte[] src2 = new byte[10000];

			byte[] v1 = new byte[1000];

			Polynomial x = null, y = null;
            int n = 0;


			BytesUtil bytesUtil = new BytesUtil();

  			final int degree = 100;
             try {
            	x = RandomPolynomial(degree);
            	y = RandomPolynomial(degree);
        	} catch(InvalidObjectException e) {
        		System.out.println();
        	}

        	 int[] res = new int[x._degree + y._degree + 1];
        	 src1 = bytesUtil.toByteArray(x);
	     	src2 = bytesUtil.toByteArray(y);

           if (MPI.COMM_WORLD.Rank() == 0) {
           		 MPI.COMM_WORLD.Bcast(src1, 0, src1.length, MPI.BYTE, 0);
                 MPI.COMM_WORLD.Bcast(src2, 0, src2.length, MPI.BYTE, 0);

                 for(int i = 0; i < (x._degree + 1) * (y._degree + 1); i++) {
                 	  req = MPI.COMM_WORLD.Irecv(v1, 0, v1.length , MPI.BYTE, MPI.ANY_SOURCE, 999);
                 	  req.Wait();
                 	  VectorElement result = (VectorElement) bytesUtil.toObject(v1);
                      res[result.Index] += result.Value;
                 }
                Polynomial output = new Polynomial(res);
                System.out.println(Arrays.equals(output._coefficients, MultiplyKaratsuba(x,y)._coefficients));
           } else {
           		 MPI.COMM_WORLD.Bcast(src1, 0, src1.length, MPI.BYTE, 0);
                 MPI.COMM_WORLD.Bcast(src2, 0, src2.length, MPI.BYTE, 0);

                Polynomial poly1 = (Polynomial) bytesUtil.toObject(src1);
      		 	Polynomial poly2 = (Polynomial) bytesUtil.toObject(src2);

  			 	n = poly1._degree;

             	Pair pair1 = MpiFor(0, n, 1, MPI.COMM_WORLD);
		        for (int i = pair1._first; i <= pair1._end; ++i) {
		        	 for (int j = 0; j <= poly2._degree; ++j) {

		        	 	v1 = bytesUtil.toByteArray(new VectorElement (i + j, poly1._coefficients[i] * poly2._coefficients[j]));
                		req = MPI.COMM_WORLD.Isend(v1, 0, v1.length, MPI.BYTE, 0, 999);
                		req.Wait();
		        	 }
		       }

           }

			MPI.COMM_WORLD.Barrier();
    		MPI.Finalize();

       }
       public static void main(String args[]) throws Exception {
       		Karatsuuuba(args);
       		//NormalMultiplicationMPI(args);
             
		}
}