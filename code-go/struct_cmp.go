package main

import (
	"fmt"

	"github.com/google/go-cmp/cmp"
)

type FareCalculate struct {
	TripID    string
	CreatedAt string
	Base      Base
}

type Base struct {
	FareRef     FareRef
	EntityFares []EntityFare
}

type EntityFare struct {
	Total float64
	Party string
}

type FareRef struct {
	FareFlowID        string
	FareFlowRequestID string
	FareFlowSessionID string
}

func main() {
	structA := FareCalculate{
		TripID:    "T1",
		CreatedAt: "1672979158",
		Base: Base{
			FareRef: FareRef{
				FareFlowID:        "F1",
				FareFlowRequestID: "FR1",
				FareFlowSessionID: "FS1",
			},
			EntityFares: []EntityFare{
				{
					Total: 12.34,
					Party: "org::driver",
				},
				{
					Total: 13.45,
					Party: "org::rider",
				},
			},
		},
	}
	structB := FareCalculate{
		TripID:    "T1",
		CreatedAt: "1672979161",
		Base: Base{
			FareRef: FareRef{
				FareFlowID:        "F1",
				FareFlowRequestID: "FR1",
				FareFlowSessionID: "FS1",
			},
			EntityFares: []EntityFare{
				{
					Total: 12.34,
					Party: "org::driver",
				},
				{
					Total: 13.49,
					Party: "org::rider",
				},
			},
		},
	}

	var reporter DiffReporter
	_ = cmp.Diff(structA, structB, cmp.Reporter(&reporter))
	if len(reporter.diffs) != 0 {
		for _, attr := range reporter.attrPaths {
			fmt.Println(attr.value)
			fmt.Println(attr.path)
		}
	}
}

// DiffReporter is a simple custom reporter that only records differences
// detected during comparison.
type DiffReporter struct {
	path      cmp.Path
	attrPaths []attrPath
	diffs     []diffPath
}

type attrPath struct {
	path  string
	value string
}

type diffPath struct {
	path     string
	expected string
	actual   string
}

func (dr *DiffReporter) PushStep(ps cmp.PathStep) {
	dr.path = append(dr.path, ps)
}

func (dr *DiffReporter) Report(rs cmp.Result) {
	l, r := dr.path.Last().Values()
	path := dr.path.GoString()
	dr.attrPaths = append(dr.attrPaths, attrPath{
		path:  path,
		value: fmt.Sprintf("%v", l),
	})
	if !rs.Equal() {
		dr.diffs = append(dr.diffs, diffPath{
			path:     path,
			expected: fmt.Sprintf("%v", l),
			actual:   fmt.Sprintf("%v", r),
		})
	}
}

func (dr *DiffReporter) PopStep() {
	dr.path = dr.path[:len(dr.path)-1]
}
