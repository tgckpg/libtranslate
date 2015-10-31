<?php

interface ByteMapCompiler {
    function branchOpen($level, \Branch $b);
    function branchValue($level, $isHead, $byteSequence, $wholeByte, $indexByte);
    function branchClose($level, $isHead);
}


class Branch
{
    // Branch
    //
    //       ____LV2 Branch Head($head) [byteSequence]
    //_Lv1__/         ____Lv3 Branch Heada [byteSequence]
    //      \____Lv2_/
    //               \____Lv3 branch
    //

    // Whole-byte
    // it means the byte itself have a value
    // but the sub branches also include the byte it self
    // Given sequence: a, aa, aa1, aa2, aa3
    // aa itself is a branch of a
    //   and aa1, aa2, aa3 is a sub branch
    //   hence aa is a wholeByte Sequence
    //   hence a is also a wholeByte Sequence
    public $wholeByte = FALSE;
    // Is branch head
    public $isHead = false;
    public $lv = 0;

    // byteSequence
    //   byteIndex => ByteValue
    private $bs = [];
    // index byte
    private $ib = 0;
    // Branches
    protected $br = [];

    // Branch value
    private $v;

    // Sequence Length
    private $l;

    function __construct($isHead = TRUE, $level = 0, $byte_index = NULL, $byte_value = NULL)
    {
        $this->isHead = $isHead;
        $this->lv = $level;
        if($byte_index !== NULL)
        {
            $this->bs[$byte_index] = $byte_value;
            $this->ib = $byte_index;
        }
    }

    public function __get($name)
    {
        switch($name)
        {
            case "byteSequence":
                return $this->bs;
            case "terminal":
                return empty($this->br);
        }
        return NULL;
    }

    public function putByte($index, $value)
    {
        $this->bs[$index] = $value;
        $this->ib = $index;
    }

    public function append(\Branch $b)
    {
        $this->br[] = $b;
    }

    public function setValue($value)
    {
        $this->v = $value;
    }


    public function setSequenceLength($length)
    {
        $this->l = $length;
    }

    public function compile($lv, \ByteMapCompiler $compiler)
    {
        $output = "";
        // Extract byte value
        $output .= $compiler->branchOpen($lv + $this->lv, $this);
        if(!empty($this->br))
        {
            foreach($this->br as $branch)
            {
                $output .= $branch->compile($lv, $compiler);
            }
        }

        if(isset($this->v))
        {
            $output .= $compiler->branchValue($lv + $this->lv, $this->v, $this->l, $this->wholeByte, $this->ib);
        }

        $output .= $compiler->branchClose($lv + $this->lv, $this->isHead);

        return $output;
    }
}

class RootBranch extends Branch
{
    function __construct()
    {
        parent::__construct();
    }

    public function compile($lv, \ByteMapCompiler $compiler)
    {
        $output = "";
        foreach($this->br as $branch)
        {
            $output .= $branch->compile($lv, $compiler);
        }
        return $output;
    }
}

class ByteMap
{
    private $logger;

    function __construct($logger = NULL)
    {
        $this->logger = $logger;
    }

    public function cascade($seq_arr)
    {
	    $this->log("\n  Sorting sequence");
    	uksort($seq_arr, [$this, 'byte_sort']);
        $this->log("...done\n");

        $seq_keys = array_map('strval', array_keys($seq_arr));
        $seq_size = sizeof($seq_keys);

        $rb = new RootBranch;
        $this->parse_sequence($seq_arr, $seq_keys, 0, $seq_size, 0, 0, $rb);
        return $rb;
    }

    protected function log($line, $lv = 0)
    {
        $line = $this->get_indent($lv) . $line;
        if($this->logger !== NULL)
        {
            $this->logger->__invoke($line);
        }
        else
        {
            echo $line;
        }
    }

    protected function byte_sort($a, $b)
    {
        $k = strlen($a) - 1;
        $l = strlen($b) - 1;
        $j = ($k > $l ? $l : $k) + 1;
        for($i = 0; $i < $j; $i ++)
        {
            if($a[$i] == $b[$i])
            {
                if($i == $l)
                return 1;
                else if($i == $k)
                return -1;
            }
            else
            {
                return ord($b[$i]) - ord($a[$i]);
            }
        }
    }

    protected function dump_sequence($sequence, $byte_index)
    {
        $str = "| ";
        $l = strlen($sequence);
        for($i = 0; $i < $l; $i ++)
        {
            if($i != $byte_index)
            {
                $str .= dechex(ord($sequence[$i]))." ";
            }
            else
            {
                $str .= "(".dechex(ord($sequence[$i])).") ";
            }
        }
        return $str;
    }


    protected function test_byte_scope($seq_arr, $seq_keys, $grp_start, $grp_end, $byte_index)
    {
        $scope_length = $grp_end - $grp_start;
        if($scope_length == 1)
        {
            return ( $byte_index < strlen($seq_keys[$grp_start]) );
        }
        else
        {
            // Minus 1 since matching is +1
            $grp_end --;
            for($i = $grp_start, $j = 1; $i < $grp_end; $i ++)
            {
                if($seq_keys[$i][$byte_index] == $seq_keys[$i + 1][$byte_index])
                {
                    $j ++;
                }
            }
        }
        return ($scope_length == $j);
    }

    protected function get_indent($l)
    {
        return str_repeat("    ", $l);
    }

    protected function parse_sequence($seq_arr, $seq_keys, $seq_start, $seq_end, $byte_index, $lv, \Branch $rBranch)
    {
        $mov_grp_a = $seq_start;
        $grp_a = $seq_start;
        $indent = $this->get_indent($lv);
        // Log level
        $llv = $lv + 1;
        $this->log("Level: $lv\n", $llv);

        while($mov_grp_a < $seq_end)
        {
        
            $ref_byte = ord($seq_keys[$mov_grp_a][$byte_index]);

            // New branch
            $thisBranch = new Branch( !( $seq_start < $mov_grp_a ), $lv, $byte_index, $ref_byte );
            
            // loop over the same byte sequence to get group anchor
            while(++$mov_grp_a < $seq_end && $ref_byte == ord($seq_keys[$mov_grp_a][$byte_index])) {	}
            // set moving byte index
            $mov_byte_i = $byte_index;
            
            // Debup info
            $this->log("Group: START $grp_a, END $mov_grp_a (". ( $mov_grp_a - $grp_a ) .")\n", $llv);
            $this->log("Matching Index: $byte_index\n", $llv);
            for($c = $grp_a; $c < $mov_grp_a; $c ++)
            {
                $this->log($this->dump_sequence($seq_keys[$c], $byte_index)."\n", $llv);
            }

            // Test the nekt byte is a group-scope byte and pad it
            $c_seq_len = strlen($seq_keys[$grp_a]);

            while((++$mov_byte_i < $c_seq_len) && $this->test_byte_scope($seq_arr, $seq_keys, $grp_a, $mov_grp_a, $mov_byte_i))
            {
                $thisBranch->putByte($mov_byte_i, ord($seq_keys[$grp_a][$mov_byte_i]));
            }

            $this->log("Index: $mov_byte_i Len: $c_seq_len\n", $llv);

            if($mov_byte_i == $c_seq_len)
            {
                if(( 1 < $mov_grp_a - $grp_a ) && $seq_keys[$grp_a][$mov_byte_i - 1] == $seq_keys[$grp_a + 1][$mov_byte_i - 1])
                {
                    $this->log("Whole byte-sequence at level: $lv\n", $llv);
                    $this->parse_sequence($seq_arr, $seq_keys, $grp_a + 1, $mov_grp_a, $mov_byte_i, $lv + 1, $thisBranch);
                    $thisBranch->wholeByte = TRUE;
                }
                $thisBranch->setSequenceLength($c_seq_len - 1);
                $thisBranch->setValue($seq_arr[$seq_keys[$grp_a]]);
            }
            else
            {
                // Start sub-level stepping
                $this->parse_sequence($seq_arr, $seq_keys, $grp_a, $mov_grp_a, $mov_byte_i, $lv + 1, $thisBranch);
            }
            // Get group index
            $grp_a = $mov_grp_a;
            $rBranch->append($thisBranch);
        }
    }

}
